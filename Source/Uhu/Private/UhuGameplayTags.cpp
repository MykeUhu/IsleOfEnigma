// Copyright MykeUhu


#include "UhuGameplayTags.h"
#include "GameplayTagsManager.h"

FUhuGameplayTags FUhuGameplayTags::GameplayTags;

void FUhuGameplayTags::InitializeNativeGameplayTags()
{
	// Primary Attributes
GameplayTags.Attributes_Primary_Strength = UGameplayTagsManager::Get().AddNativeGameplayTag(
    FName("Attributes.Primary.Strength"),
    FString("Increases melee damage, improves physical resistance")
);

GameplayTags.Attributes_Primary_Intelligence = UGameplayTagsManager::Get().AddNativeGameplayTag(
    FName("Attributes.Primary.Intelligence"),
    FString("Increases magic power and spell effectiveness")
);

GameplayTags.Attributes_Primary_Willpower = UGameplayTagsManager::Get().AddNativeGameplayTag(
    FName("Attributes.Primary.Willpower"),
    FString("Increases mana regeneration and reduces cooldowns")
);

GameplayTags.Attributes_Primary_Agility = UGameplayTagsManager::Get().AddNativeGameplayTag(
    FName("Attributes.Primary.Agility"),
    FString("Increases evasion and attack speed")
);

GameplayTags.Attributes_Primary_Stamina = UGameplayTagsManager::Get().AddNativeGameplayTag(
    FName("Attributes.Primary.Stamina"),
    FString("Increases health and physical endurance")
);

// Secondary Attributes
GameplayTags.Attributes_Secondary_Armor = UGameplayTagsManager::Get().AddNativeGameplayTag(
    FName("Attributes.Secondary.Armor"),
    FString("Reduces damage taken, improves Block Chance")
);

GameplayTags.Attributes_Secondary_MeleeAttackSpeed = UGameplayTagsManager::Get().AddNativeGameplayTag(
    FName("Attributes.Secondary.MeleeAttackSpeed"),
    FString("Increases the speed of melee attacks")
);

GameplayTags.Attributes_Secondary_PhysCritChance = UGameplayTagsManager::Get().AddNativeGameplayTag(
    FName("Attributes.Secondary.PhysCritChance"),
    FString("Increases the chance of landing a critical physical hit")
);

GameplayTags.Attributes_Secondary_MaxMana = UGameplayTagsManager::Get().AddNativeGameplayTag(
    FName("Attributes.Secondary.MaxMana"),
    FString("Increases maximum mana capacity")
);

GameplayTags.Attributes_Secondary_CastSpeed = UGameplayTagsManager::Get().AddNativeGameplayTag(
    FName("Attributes.Secondary.CastSpeed"),
    FString("Increases the speed of casting spells")
);

GameplayTags.Attributes_Secondary_SpellCritChance = UGameplayTagsManager::Get().AddNativeGameplayTag(
    FName("Attributes.Secondary.SpellCritChance"),
    FString("Increases the chance of landing a critical spell hit")
);

GameplayTags.Attributes_Secondary_ManaRegeneration = UGameplayTagsManager::Get().AddNativeGameplayTag(
    FName("Attributes.Secondary.ManaRegeneration"),
    FString("Increases the rate of mana regeneration")
);

GameplayTags.Attributes_Secondary_ManaEfficacy = UGameplayTagsManager::Get().AddNativeGameplayTag(
    FName("Attributes.Secondary.ManaEfficacy"),
    FString("Increases the efficiency of mana usage, reducing mana costs")
);

GameplayTags.Attributes_Secondary_CooldownReduction = UGameplayTagsManager::Get().AddNativeGameplayTag(
    FName("Attributes.Secondary.CooldownReduction"),
    FString("Reduces the cooldown time of abilities")
);

GameplayTags.Attributes_Secondary_Evasion = UGameplayTagsManager::Get().AddNativeGameplayTag(
    FName("Attributes.Secondary.Evasion"),
    FString("Increases the chance to dodge incoming attacks")
);

GameplayTags.Attributes_Secondary_ProjectileAttackSpeed = UGameplayTagsManager::Get().AddNativeGameplayTag(
    FName("Attributes.Secondary.ProjectileAttackSpeed"),
    FString("Increases the speed of projectile attacks")
);

GameplayTags.Attributes_Secondary_ProjectileCritChance = UGameplayTagsManager::Get().AddNativeGameplayTag(
    FName("Attributes.Secondary.ProjectileCritChance"),
    FString("Increases the chance of landing a critical projectile hit")
);

GameplayTags.Attributes_Secondary_HealthRegeneration = UGameplayTagsManager::Get().AddNativeGameplayTag(
    FName("Attributes.Secondary.HealthRegeneration"),
    FString("Increases the rate of health regeneration")
);

GameplayTags.Attributes_Secondary_MaxHealth = UGameplayTagsManager::Get().AddNativeGameplayTag(
    FName("Attributes.Secondary.MaxHealth"),
    FString("Increases maximum health capacity")
);

GameplayTags.Attributes_Secondary_MovementSpeed = UGameplayTagsManager::Get().AddNativeGameplayTag(
    FName("Attributes.Secondary.MovementSpeed"),
    FString("Increases movement speed")
);

}