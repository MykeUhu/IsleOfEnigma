// Copyright MykeUhu

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/UhuGameplayAbility.h"
#include "UhuProjectileSpell.generated.h"

class AUhuProjectile;
/**
 * 
 */
UCLASS()
class UHU_API UUhuProjectileSpell : public UUhuGameplayAbility
{
	GENERATED_BODY()

protected:

	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<AUhuProjectile> ProjectileClass;
};