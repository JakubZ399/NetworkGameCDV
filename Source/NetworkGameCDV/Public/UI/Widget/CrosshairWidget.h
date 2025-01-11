// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CrosshairWidget.generated.h"

class UTextBlock;
class UOverlay;
/**
 * 
 */
UCLASS()
class NETWORKGAMECDV_API UCrosshairWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* AmmoText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UOverlay* HitCrosshair;

	UFUNCTION(BlueprintCallable)
	void CrosshairHitEnable();

	UPROPERTY(Replicated, BlueprintReadWrite)
	int32 AmmoCurrent;
	UPROPERTY(Replicated, BlueprintReadWrite)
	int32 AmmoMax;

protected:
	virtual void NativeConstruct() override;
	
	FTimerHandle TimerHandle;
	void OnHitEnableComplete();
	
};
