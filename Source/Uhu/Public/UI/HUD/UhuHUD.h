// Copyright MykeUhu

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "UhuHUD.generated.h"

class UAttributeSet;
class UAbilitySystemComponent;
class UOverlayWidgetController;
class UUhuUserWidget;
struct FWidgetControllerParams;
/**
 * 
 */
UCLASS()
class UHU_API AUhuHUD : public AHUD
{
	GENERATED_BODY()
public:
	UPROPERTY()
	TObjectPtr<UUhuUserWidget>  OverlayWidget;

	UOverlayWidgetController* GetOverlayWidgetController(const FWidgetControllerParams& WCParams);

	void InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS);

protected:


private:

	UPROPERTY(EditAnywhere)
	TSubclassOf<UUhuUserWidget> OverlayWidgetClass;

	UPROPERTY()
	TObjectPtr<UOverlayWidgetController> OverlayWidgetController;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UOverlayWidgetController> OverlayWidgetControllerClass;
};