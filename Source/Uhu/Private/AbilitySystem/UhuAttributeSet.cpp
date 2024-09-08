// Copyright MykeUhu


#include "AbilitySystem/UhuAttributeSet.h"
#include "Net/UnrealNetwork.h"

UUhuAttributeSet::UUhuAttributeSet()
{
	InitHealth(50.f);
	InitMaxHealth(100.f);
	InitMana(50.f);
	InitMaxMana(100.f);
}

void UUhuAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, Mana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, MaxMana, COND_None, REPNOTIFY_Always);
}

void UUhuAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, Health, OldHealth);
}

void UUhuAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, MaxHealth, OldMaxHealth);
}

void UUhuAttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, Mana, OldMana);
}

void UUhuAttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, MaxMana, OldMaxMana);
}
