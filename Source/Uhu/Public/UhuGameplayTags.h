// Copyright MykeUhu

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

/**
 * UhuGameplayTags
 *
 * Singleton containing native Gameplay Tags
 */

struct FUhuGameplayTags
{
public:
	static const FUhuGameplayTags& Get() { return GameplayTags;}
	static void InitializeNativeGameplayTags();

	FGameplayTag Attributes_Primary_Strength;
	FGameplayTag Attributes_Primary_Intelligence;
	FGameplayTag Attributes_Primary_Willpower;
	FGameplayTag Attributes_Primary_Agility;
	FGameplayTag Attributes_Primary_Stamina;

	FGameplayTag Attributes_Secondary_Armor;
	FGameplayTag Attributes_Secondary_MeleeAttackSpeed;
	FGameplayTag Attributes_Secondary_PhysCritChance;
	FGameplayTag Attributes_Secondary_MaxMana;
	FGameplayTag Attributes_Secondary_CastSpeed;
	FGameplayTag Attributes_Secondary_SpellCritChance;
	FGameplayTag Attributes_Secondary_ManaRegeneration;
	FGameplayTag Attributes_Secondary_ManaEfficacy;
	FGameplayTag Attributes_Secondary_CooldownReduction;
	FGameplayTag Attributes_Secondary_Evasion;
	FGameplayTag Attributes_Secondary_ProjectileAttackSpeed;
	FGameplayTag Attributes_Secondary_ProjectileCritChance;
	FGameplayTag Attributes_Secondary_HealthRegeneration;
	FGameplayTag Attributes_Secondary_MaxHealth;
	FGameplayTag Attributes_Secondary_MovementSpeed;
	
	FGameplayTag InputTag_LMB;
	FGameplayTag InputTag_RMB;
	FGameplayTag InputTag_1;
	FGameplayTag InputTag_2;
	FGameplayTag InputTag_3;
	FGameplayTag InputTag_4;
		
private:
	static FUhuGameplayTags GameplayTags;
};