// Copyright by MykeUhu


#include "AbilitySystem/UhuAttributeSet.h"
#include "Net/UnrealNetwork.h"



UUhuAttributeSet::UUhuAttributeSet()
{
	InitHealth(100.f);
	InitMaxHealth(150.f);
	InitMana(100.f);
	InitMaxMana(150.f);
	InitEShield(0.f);
	InitMaxEShield(150.f);
}

void UUhuAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, Mana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, MaxMana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, EShield, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, MaxEShield, COND_None, REPNOTIFY_Always);
}

void UUhuAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, Health, OldHealth);
}

void UUhuAttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, Mana, OldMana);
}

void UUhuAttributeSet::OnRep_EShield(const FGameplayAttributeData& OldEShield) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, EShield, OldEShield);
}

void UUhuAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, MaxHealth, OldMaxHealth);
}

void UUhuAttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, MaxMana, OldMaxMana);
}

void UUhuAttributeSet::OnRep_MaxEShield(const FGameplayAttributeData& OldMaxEShield) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, MaxEShield, OldMaxEShield);
}
