// Copyright MykeUhu

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GameplayTagContainer.h"
#include "UhuPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
struct FInputActionValue;
class IEnemyInterface;
class UUhuInputConfig;
class UUhuAbilitySystemComponent;
class USplineComponent;

/**
 * 
 */
UCLASS()
class UHU_API AUhuPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	AUhuPlayerController();
	virtual void PlayerTick(float DeltaTime) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Debug")
	bool DebugToolsShowPathfinding = false;
	
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	
private:
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputMappingContext> UhuContext;
	
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputAction> MoveAction;
	
	void Move(const FInputActionValue& InputActionValue);
	void CursorTrace();
	
	IEnemyInterface* LastActor;
	IEnemyInterface* ThisActor;
	
	void AbilityInputTagPressed(FGameplayTag InputTag);
	void AbilityInputTagReleased(FGameplayTag InputTag);
	void AbilityInputTagHeld(FGameplayTag InputTag);
	FHitResult CursorHit;
	
	UPROPERTY(EditDefaultsOnly, Category="Input")
	TObjectPtr<UUhuInputConfig> InputConfig;
	
	UPROPERTY()
	TObjectPtr<UUhuAbilitySystemComponent> UhuAbilitySystemComponent;

	UUhuAbilitySystemComponent* GetASC();


	FVector CachedDestination = FVector::ZeroVector;
	float FollowTime = 0.f;
	float ShortPressThreshold = 0.5f;
	bool bAutoRunning = false;
	bool bTargeting = false;

	UPROPERTY(EditDefaultsOnly)
	float AutoRunAcceptanceRadius = 50.f;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USplineComponent> Spline;

	void AutoRun();
};
