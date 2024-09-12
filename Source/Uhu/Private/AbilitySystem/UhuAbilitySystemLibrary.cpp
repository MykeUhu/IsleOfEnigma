// Copyright MykeUhu


#include "AbilitySystem/UhuAbilitySystemLibrary.h"

#include "Kismet/GameplayStatics.h"
#include "Player/UhuPlayerState.h"
#include "UI/HUD/UhuHUD.h"
#include "UI/WidgetController/UhuWidgetController.h"


UOverlayWidgetController* UUhuAbilitySystemLibrary::GetOverlayWidgetController(const UObject* WorldContextObject)
{
	if (APlayerController* PC = UGameplayStatics::GetPlayerController(WorldContextObject, 0))
	{
		if (AUhuHUD* UhuHUD = Cast<AUhuHUD>(PC->GetHUD()))
		{
			AUhuPlayerState* PS = PC->GetPlayerState<AUhuPlayerState>();
			UAbilitySystemComponent* ASC = PS->GetAbilitySystemComponent();
			UAttributeSet* AS = PS->GetAttributeSet();
			const FWidgetControllerParams WidgetControllerParams(PC, PS, ASC, AS);
			return UhuHUD->GetOverlayWidgetController(WidgetControllerParams);
		}
	}
	return nullptr;
}

UAttributeMenuWidgetController* UUhuAbilitySystemLibrary::GetAttributeMenuWidgetController(
	const UObject* WorldContextObject)
{
	if (APlayerController* PC = UGameplayStatics::GetPlayerController(WorldContextObject, 0))
	{
		if (AUhuHUD* UhuHUD = Cast<AUhuHUD>(PC->GetHUD()))
		{
			AUhuPlayerState* PS = PC->GetPlayerState<AUhuPlayerState>();
			UAbilitySystemComponent* ASC = PS->GetAbilitySystemComponent();
			UAttributeSet* AS = PS->GetAttributeSet();
			const FWidgetControllerParams WidgetControllerParams(PC, PS, ASC, AS);
			return UhuHUD->GetAttributeMenuWidgetController(WidgetControllerParams);
		}
	}
	return nullptr;
}
