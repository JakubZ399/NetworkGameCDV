// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/CrosshairWidget.h"
#include "Components/Overlay.h"
#include "Net/UnrealNetwork.h"


void UCrosshairWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if(HitCrosshair)
	{
		HitCrosshair->SetVisibility(ESlateVisibility::Hidden);
	}
}

void UCrosshairWidget::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UCrosshairWidget, AmmoCurrent);
	DOREPLIFETIME(UCrosshairWidget, AmmoMax);
}

void UCrosshairWidget::CrosshairHitEnable()
{
	if (HitCrosshair)
	{
		HitCrosshair->SetVisibility(ESlateVisibility::Visible);
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &UCrosshairWidget::OnHitEnableComplete, 0.075, false);
	}

}

void UCrosshairWidget::OnHitEnableComplete()
{
	HitCrosshair->SetVisibility(ESlateVisibility::Hidden);
}

//Ammo Update
