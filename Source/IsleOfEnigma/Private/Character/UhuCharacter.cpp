// Copyright by MykeUhu


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

	// If need to Zoom -> true, make sure that you set back at begin of running
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	
	
}

void AUhuCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	// Init ability Actor Info for the Server
	InitAbilityActorInfo();
}

void AUhuCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	// Init ability Actor Info for the Client
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
