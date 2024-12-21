// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "LobbyGameState.generated.h"

/**
 * 
 */
UCLASS()
class NETWORKGAMECDV_API ALobbyGameState : public AGameState
{
	GENERATED_BODY()

public:
	UPROPERTY(Replicated, BlueprintReadWrite)
	int32 CurrentPlayers = 0;

	UPROPERTY(Replicated, BlueprintReadWrite)
	int32 ReadyPlayers = 0;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	int32 RequiredPlayers = 2;

	void IncrementPlayerCount();
	void DecrementPlayerCount();
	void SetPlayerReady(bool bReady);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnLobbyStateUpdated);

	UPROPERTY(BlueprintAssignable)
	FOnLobbyStateUpdated OnLobbyStateUpdated;

private:
	void CheckReadyStatus();
};
