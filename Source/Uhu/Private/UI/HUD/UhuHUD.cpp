// Copyright MykeUhu


#include "UI/HUD/UhuHUD.h"

#include "UI/Widget/UhuUserWidget.h"

void AUhuHUD::BeginPlay()
{
	Super::BeginPlay();

	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	Widget->AddToViewport();

}
