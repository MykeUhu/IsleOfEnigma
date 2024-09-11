// Copyright MykeUhu

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "UhuHUD.generated.h"

class UAttributeMenuWidgetController;
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

	UOverlayWidgetController* GetOverlayWidgetController(const FWidgetControllerParams& WCParams);

	UAttributeMenuWidgetController* GetAttributeMenuWidgetController(const FWidgetControllerParams& WCParams);

	void InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS);

protected:


private:
	
	UPROPERTY()
	TObjectPtr<UUhuUserWidget>  OverlayWidget;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UUhuUserWidget> OverlayWidgetClass;

	UPROPERTY()
	TObjectPtr<UOverlayWidgetController> OverlayWidgetController;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UOverlayWidgetController> OverlayWidgetControllerClass;
	
	UPROPERTY()
	TObjectPtr<UAttributeMenuWidgetController> AttributeMenuWidgetController;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UAttributeMenuWidgetController> AttributeMenuWidgetControllerClass;
};