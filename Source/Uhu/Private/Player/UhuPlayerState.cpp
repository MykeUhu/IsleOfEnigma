// Copyright MykeUhu


#include "Player/UhuPlayerState.h"
#include "AbilitySystem/UhuAbilitySystemComponent.h"
#include "AbilitySystem/UhuAttributeSet.h"

AUhuPlayerState::AUhuPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UUhuAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<UUhuAttributeSet>("AttributeSet");
	NetUpdateFrequency = 100.f;
}

UAbilitySystemComponent* AUhuPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}