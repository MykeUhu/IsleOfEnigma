// Copyright MykeUhu


#include "Character/UhuCharacter.h"
#include "AbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/UhuPlayerState.h"

AUhuCharacter::AUhuCharacter()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
}

void AUhuCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	// Init ability actor info for the Server
	InitAbilityActorInfo();
}

void AUhuCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	// Init ability actor info for the Client
	InitAbilityActorInfo();
}

void AUhuCharacter::InitAbilityActorInfo()
{
	AUhuPlayerState* UhuPlayerState = GetPlayerState<AUhuPlayerState>();
	check(UhuPlayerState);
	UhuPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(UhuPlayerState, this);
	AbilitySystemComponent = UhuPlayerState->GetAbilitySystemComponent();
	AttributeSet = UhuPlayerState->GetAttributeSet();
}