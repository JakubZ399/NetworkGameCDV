// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "MilitaryPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class NETWORKGAMECDV_API AMilitaryPlayerState : public APlayerState
{
	GENERATED_BODY()

protected:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	
public:
	UFUNCTION(BlueprintCallable)
	void UpdateKills();

	UFUNCTION(BlueprintCallable)
	void UpdateDeath();

	UFUNCTION(BlueprintCallable)
	bool CheckKills();

	UPROPERTY(Replicated)
	int32 PlayerNumberOfKills{0};
	
	UPROPERTY(Replicated)
	int32 PlayerNumberOfDeaths{0};

	UPROPERTY(EditAnywhere, Category = "APlayerStats")
	int32 KillsToEndRound{10};
};
