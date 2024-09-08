// Copyright MykeUhu


#include "UI/WidgetController/OverlayWidgetController.h"
#include "AbilitySystem/UhuAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	const UUhuAttributeSet* UhuAttributeSet = CastChecked<UUhuAttributeSet>(AttributeSet);

	OnHealthChanged.Broadcast(UhuAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(UhuAttributeSet->GetMaxHealth());
	OnManaChanged.Broadcast(UhuAttributeSet->GetMana());
	OnMaxManaChanged.Broadcast(UhuAttributeSet->GetMaxMana());
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	const UUhuAttributeSet* UhuAttributeSet = CastChecked<UUhuAttributeSet>(AttributeSet);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		UhuAttributeSet->GetHealthAttribute()).AddUObject(this, &UOverlayWidgetController::HealthChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		UhuAttributeSet->GetMaxHealthAttribute()).AddUObject(this, &UOverlayWidgetController::MaxHealthChanged);
	
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		UhuAttributeSet->GetManaAttribute()).AddUObject(this, &UOverlayWidgetController::ManaChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		UhuAttributeSet->GetMaxManaAttribute()).AddUObject(this, &UOverlayWidgetController::MaxManaChanged);
}

void UOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& Data) const
{
	OnHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::ManaChanged(const FOnAttributeChangeData& Data) const
{
	OnManaChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxManaChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxManaChanged.Broadcast(Data.NewValue);
}
