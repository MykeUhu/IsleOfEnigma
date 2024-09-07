// Copyright MykeUhu

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "UhuCharacterBase.generated.h"

UCLASS(Abstract)
class UHU_API AUhuCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	AUhuCharacterBase();

protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere, Category = "Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;
};
