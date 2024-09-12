// Copyright MykeUhu


#include "Player/UhuPlayerController.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "UhuGameplayTags.h"
#include "EnhancedInputSubsystems.h"
#include "NavigationPath.h"
#include "NavigationSystem.h"
#include "AbilitySystem/UhuAbilitySystemComponent.h"
#include "Components/SplineComponent.h"
#include "Input/UhuInputComponent.h"
#include "Interaction/EnemyInterface.h"

AUhuPlayerController::AUhuPlayerController()
{
	bReplicates = true;
	Spline = CreateDefaultSubobject<USplineComponent>("Spline");
}

void AUhuPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
	CursorTrace();
	AutoRun();
}
void AUhuPlayerController::AutoRun()
{
	if (!bAutoRunning) return;
	if (APawn* ControlledPawn = GetPawn())
	{
		const FVector LocationOnSpline = Spline->FindLocationClosestToWorldLocation(ControlledPawn->GetActorLocation(), ESplineCoordinateSpace::World);
		const FVector Direction = Spline->FindDirectionClosestToWorldLocation(LocationOnSpline, ESplineCoordinateSpace::World);
		ControlledPawn->AddMovementInput(Direction);
		const float DistanceToDestination = (LocationOnSpline - CachedDestination).Length();
		if (DistanceToDestination <= AutoRunAcceptanceRadius)
		{
			bAutoRunning = false;
		}
	}
}

void AUhuPlayerController::CursorTrace()
{
	GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);
	if (!CursorHit.bBlockingHit) return;

	LastActor = ThisActor;
	ThisActor = Cast<IEnemyInterface>(CursorHit.GetActor());

	if (LastActor != ThisActor)
	{
		if (LastActor) LastActor->UnHighlightActor();
		if (ThisActor) ThisActor->HighlightActor();
	}
}

void AUhuPlayerController::AbilityInputTagPressed(FGameplayTag InputTag)
{
	if (InputTag.MatchesTagExact(FUhuGameplayTags::Get().InputTag_LMB))
	{
		bTargeting = ThisActor ? true : false;
		bAutoRunning = false;
	}
}
void AUhuPlayerController::AbilityInputTagReleased(FGameplayTag InputTag)
{
	if (!InputTag.MatchesTagExact(FUhuGameplayTags::Get().InputTag_LMB))
	{
		if (GetASC()) GetASC()->AbilityInputTagReleased(InputTag);
		return;
	}

	if (bTargeting)
	{
		if (GetASC()) GetASC()->AbilityInputTagReleased(InputTag);
	}
	else
	{
		const APawn* ControlledPawn = GetPawn();
		if (FollowTime <= ShortPressThreshold && ControlledPawn)
		{
			if (UNavigationPath* NavPath = UNavigationSystemV1::FindPathToLocationSynchronously(this, ControlledPawn->GetActorLocation(), CachedDestination))
			{
				Spline->ClearSplinePoints();
				for (const FVector& PointLoc : NavPath->PathPoints)
				{
					Spline->AddSplinePoint(PointLoc, ESplineCoordinateSpace::World);
					//Uhu Dev Tools -> Show In Debug Menu bubbles
					if (DebugToolsShowPathfinding) DrawDebugSphere(GetWorld(), PointLoc, 8.f, 8, FColor::Green, false, 5.f);
				}
				CachedDestination = NavPath->PathPoints[NavPath->PathPoints.Num() - 1];
				bAutoRunning = true;
			}
		}
		FollowTime = 0.f;
		bTargeting = false;
	}
}
void AUhuPlayerController::AbilityInputTagHeld(FGameplayTag InputTag)
{
	if (!InputTag.MatchesTagExact(FUhuGameplayTags::Get().InputTag_LMB))
	{
		if (GetASC()) GetASC()->AbilityInputTagHeld(InputTag);
		return;
	}

	if (bTargeting)
	{
		if (GetASC()) GetASC()->AbilityInputTagHeld(InputTag);
	}
	else
	{
		FollowTime += GetWorld()->GetDeltaSeconds();
		if (CursorHit.bBlockingHit) CachedDestination = CursorHit.ImpactPoint;

		if (APawn* ControlledPawn = GetPawn())
		{
			const FVector WorldDirection = (CachedDestination - ControlledPawn->GetActorLocation()).GetSafeNormal();
			ControlledPawn->AddMovementInput(WorldDirection);
		}
	}
}
UUhuAbilitySystemComponent* AUhuPlayerController::GetASC()
{
	if (UhuAbilitySystemComponent == nullptr)
	{
		UhuAbilitySystemComponent = Cast<UUhuAbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetPawn<APawn>()));
	}
	return UhuAbilitySystemComponent;
}
void AUhuPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(UhuContext);
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (Subsystem)
	{
		Subsystem->AddMappingContext(UhuContext, 0);
	}
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}
void AUhuPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	UUhuInputComponent* UhuInputComponent = CastChecked<UUhuInputComponent>(InputComponent);
	UhuInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AUhuPlayerController::Move);
	UhuInputComponent->BindAbilityActions(InputConfig, this, &ThisClass::AbilityInputTagPressed, &ThisClass::AbilityInputTagReleased, &ThisClass::AbilityInputTagHeld);
}
void AUhuPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);
	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
}