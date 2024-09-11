// Copyright MykeUhu

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetController/UhuWidgetController.h"
#include "AttributeMenuWidgetController.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class UHU_API UAttributeMenuWidgetController : public UUhuWidgetController
{
	GENERATED_BODY()
public:
	virtual void BindCallbacksToDependencies() override;
	virtual void BroadcastInitialValues() override;
};