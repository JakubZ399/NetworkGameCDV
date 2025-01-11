// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MilitaryHUD.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnWidgetChange, UCrosshairWidget*, UserWidget);

class UCrosshairWidget;
/**
 * 
 */
UCLASS()
class NETWORKGAMECDV_API AMilitaryHUD : public AHUD
{
	GENERATED_BODY()

public:
	
	UCrosshairWidget* WidgetSetup();

	UPROPERTY(BlueprintAssignable)
	FOnWidgetChange OnWidgetChange;
	
protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<UCrosshairWidget> UserWidgetClass;

private:
	UPROPERTY()
	UCrosshairWidget* UserWidget;

public:
	void ResetCrosshairWidget();
};
