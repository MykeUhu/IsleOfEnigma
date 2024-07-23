// Copyright by MykeUhu


#include "Character/UhuCharacter.h"

#include "GameFramework/CharacterMovementComponent.h"

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
