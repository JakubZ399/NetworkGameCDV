// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "MilitaryGameMode.generated.h"

/**
 * 
 */
UCLASS()
class NETWORKGAMECDV_API AMilitaryGameMode : public AGameMode
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	void BackToLobby();
	
};
