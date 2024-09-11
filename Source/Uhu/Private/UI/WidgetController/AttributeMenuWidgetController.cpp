// Copyright MykeUhu


#include "UI/WidgetController/AttributeMenuWidgetController.h"

#include "AbilitySystem/UhuAttributeSet.h"
#include "AbilitySystem/Data/AttributeInfo.h"
#include "UhuGameplayTags.h"


void UAttributeMenuWidgetController::BindCallbacksToDependencies()
{

}

void UAttributeMenuWidgetController::BroadcastInitialValues()
{
	UUhuAttributeSet* AS = CastChecked<UUhuAttributeSet>(AttributeSet);

	check(AttributeInfo);

	FUhuAttributeInfo Info = AttributeInfo->FindAttributeInfoForTag(FUhuGameplayTags::Get().Attributes_Primary_Strength);
	Info.AttributeValue = AS->GetStrength();
	AttributeInfoDelegate.Broadcast(Info);
}