// Copyright MykeUhu

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "UhuAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

USTRUCT()
struct FEffectProperties
{
	GENERATED_BODY()

	FEffectProperties(){}

	FGameplayEffectContextHandle EffectContextHandle;

	UPROPERTY()
	UAbilitySystemComponent* SourceASC = nullptr;

	UPROPERTY()
	AActor* SourceAvatarActor = nullptr;

	UPROPERTY()
	AController* SourceController = nullptr;

	UPROPERTY()
	ACharacter* SourceCharacter = nullptr;

	UPROPERTY()
	UAbilitySystemComponent* TargetASC = nullptr;

	UPROPERTY()
	AActor* TargetAvatarActor = nullptr;

	UPROPERTY()
	AController* TargetController = nullptr;

	UPROPERTY()
	ACharacter* TargetCharacter = nullptr;
};

/**
 * Class representing a set of attributes for an object or character.
 * Inherits from UAttributeSet. Clicked do you like this answer -> NO! (AI Generated)
 */
UCLASS()
class UHU_API UUhuAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UUhuAttributeSet();
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	
	/*
	 * Vital Attributes
	*/
		virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health, Category = "Primary Attributes")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UUhuAttributeSet, Health);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Mana, Category = "Primary Attributes")
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UUhuAttributeSet, Mana);
	
	/*
	 * Primary Attributes
	 */
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Strength, Category = "Primary Attributes")
	FGameplayAttributeData Strength;
	ATTRIBUTE_ACCESSORS(UUhuAttributeSet, Strength);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Intelligence, Category = "Primary Attributes")
	FGameplayAttributeData Intelligence;
	ATTRIBUTE_ACCESSORS(UUhuAttributeSet, Intelligence);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Willpower, Category = "Primary Attributes")
	FGameplayAttributeData Willpower;
	ATTRIBUTE_ACCESSORS(UUhuAttributeSet, Willpower);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Agility, Category = "Primary Attributes")
	FGameplayAttributeData Agility;
	ATTRIBUTE_ACCESSORS(UUhuAttributeSet, Agility);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Stamina, Category = "Primary Attributes")
	FGameplayAttributeData Stamina;
	ATTRIBUTE_ACCESSORS(UUhuAttributeSet, Stamina);
	
	/*
	 * Secondary Attributes
	 */
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Armor, Category = "Secondary Attributes")
	FGameplayAttributeData Armor;
	ATTRIBUTE_ACCESSORS(UUhuAttributeSet, Armor);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MeleeAttackSpeed, Category = "Secondary Attributes")
	FGameplayAttributeData MeleeAttackSpeed;
	ATTRIBUTE_ACCESSORS(UUhuAttributeSet, MeleeAttackSpeed);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_PhysicalCritChance, Category = "Secondary Attributes")
	FGameplayAttributeData PhysicalCritChance;
	ATTRIBUTE_ACCESSORS(UUhuAttributeSet, PhysicalCritChance);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxMana, Category = "Secondary Attributes")
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(UUhuAttributeSet, MaxMana);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_CastSpeed, Category = "Secondary Attributes")
	FGameplayAttributeData CastSpeed;
	ATTRIBUTE_ACCESSORS(UUhuAttributeSet, CastSpeed);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_SpellCritChance, Category = "Secondary Attributes")
	FGameplayAttributeData SpellCritChance;
	ATTRIBUTE_ACCESSORS(UUhuAttributeSet, SpellCritChance);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_ManaRegeneration, Category = "Secondary Attributes")
	FGameplayAttributeData ManaRegeneration;
	ATTRIBUTE_ACCESSORS(UUhuAttributeSet, ManaRegeneration);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_CooldownReduction, Category = "Secondary Attributes")
	FGameplayAttributeData CooldownReduction;
	ATTRIBUTE_ACCESSORS(UUhuAttributeSet, CooldownReduction);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_ManaEfficiency, Category = "Secondary Attributes")
	FGameplayAttributeData ManaEfficiency;
	ATTRIBUTE_ACCESSORS(UUhuAttributeSet, ManaEfficiency);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Evasion, Category = "Secondary Attributes")
	FGameplayAttributeData Evasion;
	ATTRIBUTE_ACCESSORS(UUhuAttributeSet, Evasion);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_ProjectileAttackSpeed, Category = "Secondary Attributes")
	FGameplayAttributeData ProjectileAttackSpeed;
	ATTRIBUTE_ACCESSORS(UUhuAttributeSet, ProjectileAttackSpeed);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_ProjectileCritChance, Category = "Secondary Attributes")
	FGameplayAttributeData ProjectileCritChance;
	ATTRIBUTE_ACCESSORS(UUhuAttributeSet, ProjectileCritChance);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_HealthRegeneration, Category = "Secondary Attributes")
	FGameplayAttributeData HealthRegeneration;
	ATTRIBUTE_ACCESSORS(UUhuAttributeSet, HealthRegeneration);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth, Category = "Secondary Attributes")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UUhuAttributeSet, MaxHealth);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MovementSpeed, Category = "Secondary Attributes")
	FGameplayAttributeData MovementSpeed;
	ATTRIBUTE_ACCESSORS(UUhuAttributeSet, MovementSpeed);

	/*
	* Vital Attributes
	*/
	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth) const;

	UFUNCTION()
	void OnRep_Mana(const FGameplayAttributeData& OldMana) const;

	/*
	* Primary Attributes
	*/
	UFUNCTION()
	void OnRep_Strength(const FGameplayAttributeData& OldStrength) const;

	UFUNCTION()
	void OnRep_Intelligence(const FGameplayAttributeData& OldIntelligence) const;

	UFUNCTION()
	void OnRep_Willpower(const FGameplayAttributeData& OldWillpower) const;

	UFUNCTION()
	void OnRep_Agility(const FGameplayAttributeData& OldAgility) const;

	UFUNCTION()
	void OnRep_Stamina(const FGameplayAttributeData& OldStamina) const;

	/*
	* Secondary Attributes
	*/
	UFUNCTION()
	void OnRep_Armor(const FGameplayAttributeData& OldArmor) const;

	UFUNCTION()
	void OnRep_MeleeAttackSpeed(const FGameplayAttributeData& OldMeleeAttackSpeed) const;

	UFUNCTION()
	void OnRep_PhysicalCritChance(const FGameplayAttributeData& OldPhysicalCritChance) const;

	UFUNCTION()
	void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const;

	UFUNCTION()
	void OnRep_CastSpeed(const FGameplayAttributeData& OldCastSpeed) const;

	UFUNCTION()
	void OnRep_SpellCritChance(const FGameplayAttributeData& OldSpellCritChance) const;

	UFUNCTION()
	void OnRep_ManaRegeneration(const FGameplayAttributeData& OldManaRegeneration) const;

	UFUNCTION()
	void OnRep_CooldownReduction(const FGameplayAttributeData& OldCooldownReduction) const;

	UFUNCTION()
	void OnRep_ManaEfficiency(const FGameplayAttributeData& OldManaEfficiency) const;

	UFUNCTION()
	void OnRep_Evasion(const FGameplayAttributeData& OldEvasion) const;

	UFUNCTION()
	void OnRep_ProjectileAttackSpeed(const FGameplayAttributeData& OldProjectileAttackSpeed) const;

	UFUNCTION()
	void OnRep_ProjectileCritChance(const FGameplayAttributeData& OldProjectileCritChance) const;

	UFUNCTION()
	void OnRep_HealthRegeneration(const FGameplayAttributeData& OldHealthRegeneration) const;

	UFUNCTION()
	void OnRep_MovementSpeed(const FGameplayAttributeData& OldMovementSpeed) const;
	
	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;
	
private:
	void SetEffectProperties(const FGameplayEffectModCallbackData& Data, FEffectProperties& Props) const;
	
};
