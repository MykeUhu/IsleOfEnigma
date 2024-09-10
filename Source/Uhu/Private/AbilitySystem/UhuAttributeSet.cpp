// Copyright MykeUhu


#include "AbilitySystem/UhuAttributeSet.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "GameFramework/Character.h"
#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"

UUhuAttributeSet::UUhuAttributeSet()
{

}

void UUhuAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	/*
	* Vital Attributes
	*/
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);

	/*
	 * Primary Attributes
	*/
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, Strength, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, Intelligence, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, Willpower, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, Agility, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, Stamina, COND_None, REPNOTIFY_Always);

	/*
	 * Secondary Attributes
	 */
	// Strength
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, Armor, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, MeleeAttackSpeed, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, PhysicalCritChance, COND_None, REPNOTIFY_Always);
	// Intelligence
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, MaxMana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, CastSpeed, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, SpellCritChance, COND_None, REPNOTIFY_Always);
	// Willpower
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, ManaRegeneration, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, CooldownReduction, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, ManaEfficiency, COND_None, REPNOTIFY_Always);
	// Agility
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, Evasion, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, ProjectileAttackSpeed, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, ProjectileCritChance, COND_None, REPNOTIFY_Always);
	// Stamina
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, HealthRegeneration, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, MovementSpeed, COND_None, REPNOTIFY_Always);

	
}

void UUhuAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);
	if (Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxHealth());
	}
	if (Attribute == GetManaAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxMana());
	}
}

/*
* Vital Attributes
*/

void UUhuAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, Health, OldHealth);
}

void UUhuAttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, Mana, OldMana);
}


/*
* Primary Attributes
*/

void UUhuAttributeSet::OnRep_Strength(const FGameplayAttributeData& OldStrength) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, Strength, OldStrength);
}

void UUhuAttributeSet::OnRep_Intelligence(const FGameplayAttributeData& OldIntelligence) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, Intelligence, OldIntelligence);
}

void UUhuAttributeSet::OnRep_Willpower(const FGameplayAttributeData& OldWillpower) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, Willpower, OldWillpower);
}

void UUhuAttributeSet::OnRep_Agility(const FGameplayAttributeData& OldAgility) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, Agility, OldAgility);
}

void UUhuAttributeSet::OnRep_Stamina(const FGameplayAttributeData& OldStamina) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, Stamina, OldStamina);
}

/*
* Secondary Attributes
*/

void UUhuAttributeSet::OnRep_Armor(const FGameplayAttributeData& OldArmor) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, Armor, OldArmor);
}

void UUhuAttributeSet::OnRep_MeleeAttackSpeed(const FGameplayAttributeData& OldMeleeAttackSpeed) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, MeleeAttackSpeed, OldMeleeAttackSpeed);
}

void UUhuAttributeSet::OnRep_PhysicalCritChance(const FGameplayAttributeData& OldPhysicalCritChance) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, PhysicalCritChance, OldPhysicalCritChance);
}

void UUhuAttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, MaxMana, OldMaxMana);
}

void UUhuAttributeSet::OnRep_CastSpeed(const FGameplayAttributeData& OldCastSpeed) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, CastSpeed, OldCastSpeed);
}

void UUhuAttributeSet::OnRep_SpellCritChance(const FGameplayAttributeData& OldSpellCritChance) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, SpellCritChance, OldSpellCritChance);
}

void UUhuAttributeSet::OnRep_ManaRegeneration(const FGameplayAttributeData& OldManaRegeneration) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, ManaRegeneration, OldManaRegeneration);
}

void UUhuAttributeSet::OnRep_CooldownReduction(const FGameplayAttributeData& OldCooldownReduction) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, CooldownReduction, OldCooldownReduction);
}

void UUhuAttributeSet::OnRep_ManaEfficiency(const FGameplayAttributeData& OldManaEfficiency) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, ManaEfficiency, OldManaEfficiency);
}

void UUhuAttributeSet::OnRep_Evasion(const FGameplayAttributeData& OldEvasion) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, Evasion, OldEvasion);
}

void UUhuAttributeSet::OnRep_ProjectileAttackSpeed(const FGameplayAttributeData& OldProjectileAttackSpeed) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, ProjectileAttackSpeed, OldProjectileAttackSpeed);
}

void UUhuAttributeSet::OnRep_ProjectileCritChance(const FGameplayAttributeData& OldProjectileCritChance) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, ProjectileCritChance, OldProjectileCritChance);
}

void UUhuAttributeSet::OnRep_HealthRegeneration(const FGameplayAttributeData& OldHealthRegeneration) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, HealthRegeneration, OldHealthRegeneration);
}

void UUhuAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, MaxHealth, OldMaxHealth);
}

void UUhuAttributeSet::OnRep_MovementSpeed(const FGameplayAttributeData& OldMovementSpeed) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, MovementSpeed, OldMovementSpeed);
}



void UUhuAttributeSet::SetEffectProperties(const FGameplayEffectModCallbackData& Data, FEffectProperties& Props) const
{
	// Source = causer of the effect, Target = target of the effect (owner of this AS)

	Props.EffectContextHandle = Data.EffectSpec.GetContext();
	Props.SourceASC = Props.EffectContextHandle.GetOriginalInstigatorAbilitySystemComponent();

	if (IsValid(Props.SourceASC) && Props.SourceASC->AbilityActorInfo.IsValid() && Props.SourceASC->AbilityActorInfo->AvatarActor.IsValid())
	{
		Props.SourceAvatarActor = Props.SourceASC->AbilityActorInfo->AvatarActor.Get();
		Props.SourceController = Props.SourceASC->AbilityActorInfo->PlayerController.Get();
		if (Props.SourceController == nullptr && Props.SourceAvatarActor != nullptr)
		{
			if (const APawn* Pawn = Cast<APawn>(Props.SourceAvatarActor))
			{
				Props.SourceController = Pawn->GetController();
			}
		}
		if (Props.SourceController)
		{
			ACharacter* SourceCharacter = Cast<ACharacter>(Props.SourceController->GetPawn());
		}
	}

	if (Data.Target.AbilityActorInfo.IsValid() && Data.Target.AbilityActorInfo->AvatarActor.IsValid())
	{
		Props.TargetAvatarActor = Data.Target.AbilityActorInfo->AvatarActor.Get();
		Props.TargetController = Data.Target.AbilityActorInfo->PlayerController.Get();
		Props.TargetCharacter = Cast<ACharacter>(Props.TargetAvatarActor);
		Props.TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Props.TargetAvatarActor);
	}
}

void UUhuAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	FEffectProperties Props;
	SetEffectProperties(Data, Props);
	
	if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		SetHealth(FMath::Clamp(GetHealth(), 0.f, GetMaxHealth()));
	}
	if (Data.EvaluatedData.Attribute == GetManaAttribute())
	{
		SetMana(FMath::Clamp(GetMana(), 0.f, GetMaxMana()));
	}

}

