// Fill out your copyright notice in the Description page of Project Settings.


#include "MilitaryGameMode.h"

void AMilitaryGameMode::BackToLobby()
{
	if (HasAuthority())
	{
		UWorld* World = GetWorld();
		if (World)
		{
			World->ServerTravel(TEXT("/Game/Level/Lobby"));
		}
	}
}
