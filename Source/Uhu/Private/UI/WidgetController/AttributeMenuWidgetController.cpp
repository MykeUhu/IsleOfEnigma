// Copyright MykeUhu


#include "UI/WidgetController/AttributeMenuWidgetController.h"

#include "AbilitySystem/UhuAttributeSet.h"
#include "AbilitySystem/Data/AttributeInfo.h"
#include "UhuGameplayTags.h"


void UAttributeMenuWidgetController::BindCallbacksToDependencies()
{
	UUhuAttributeSet* AS = CastChecked<UUhuAttributeSet>(AttributeSet);
	check(AttributeInfo);
	for (auto& Pair : AS->TagsToAttributes)
	{
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(Pair.Value()).AddLambda(
		[this, Pair](const FOnAttributeChangeData& Data)
		{
			BroadcastAttributeInfo(Pair.Key, Pair.Value());
		}
	);
	}
}

void UAttributeMenuWidgetController::BroadcastInitialValues()
{
	UUhuAttributeSet* AS = CastChecked<UUhuAttributeSet>(AttributeSet);

	check(AttributeInfo);

	for (auto& Pair : AS->TagsToAttributes)
	{
		BroadcastAttributeInfo(Pair.Key, Pair.Value());
	}
}

void UAttributeMenuWidgetController::BroadcastAttributeInfo(const FGameplayTag& AttributeTag, const FGameplayAttribute& Attribute) const
{
	FUhuAttributeInfo Info = AttributeInfo->FindAttributeInfoForTag(AttributeTag);
	Info.AttributeValue = Attribute.GetNumericValue(AttributeSet);
	AttributeInfoDelegate.Broadcast(Info);
}