// Copyright MykeUhu


#include "UI/WidgetController/UhuWidgetController.h"

void UUhuWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WCParams)
{
	PlayerController = WCParams.PlayerController;
	PlayerState = WCParams.PlayerState;
	AbilitySystemComponent = WCParams.AbilitySystemComponent;
	AttributeSet = WCParams.AttributeSet;
}

void UUhuWidgetController::BroadcastInitialValues()
{

}

void UUhuWidgetController::BindCallbacksToDependencies()
{

}