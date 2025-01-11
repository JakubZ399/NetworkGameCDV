// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HUD/MilitaryHUD.h"
#include "UI/Widget/CrosshairWidget.h"
#include "Blueprint/UserWidget.h"

void AMilitaryHUD::BeginPlay()
{
	Super::BeginPlay();
}

UCrosshairWidget* AMilitaryHUD::WidgetSetup()
{
	APlayerController* PlayerController = GetOwningPlayerController();

	if(PlayerController && UserWidgetClass)
	{
		if (!UserWidget)
		{
			UserWidget = CreateWidget<UCrosshairWidget>(PlayerController, UserWidgetClass);
			if(UserWidget)
			{
				UserWidget->AddToViewport();
				OnWidgetChange.Broadcast(UserWidget);
			}
		}
		return UserWidget;
	}
	return nullptr;
}
