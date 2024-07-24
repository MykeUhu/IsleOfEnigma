// Copyright by MykeUhu

#pragma once

#include "CoreMinimal.h"
#include "Character/UhuCharacterBase.h"
#include "UhuCharacter.generated.h"

/**
 * 
 */
UCLASS()
class ISLEOFENIGMA_API AUhuCharacter : public AUhuCharacterBase
{
	GENERATED_BODY()

public:
	AUhuCharacter();

	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

private:
	void InitAbilityActorInfo();
};
