// Fill out your copyright notice in the Description page of Project Settings.


#include "MilitaryGameMode.h"

void AMilitaryGameMode::BackToLobby()
{
	if (HasAuthority())
	{
		UWorld* World = GetWorld();
		if (World)
		{
			// Inform all players to travel to the new map
			for (FConstPlayerControllerIterator Iterator = World->GetPlayerControllerIterator(); Iterator; ++Iterator)
			{
				APlayerController* PlayerController = Iterator->Get();
				if (PlayerController && PlayerController->IsLocalController() == false) // Ensure this is a client
				{
					PlayerController->ClientTravel(TEXT("/Game/Level/Lobby"), TRAVEL_Absolute);
				}
			}

			// Server travels to the lobby
			World->ServerTravel(TEXT("/Game/Level/Lobby"));
		}
	}
}
