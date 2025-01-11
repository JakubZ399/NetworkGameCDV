// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/MilitaryPlayerState.h"

#include "Net/UnrealNetwork.h"

void AMilitaryPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ThisClass, PlayerNumberOfKills);
	DOREPLIFETIME(ThisClass, PlayerNumberOfDeaths);
	
}

void AMilitaryPlayerState::UpdateKills()
{
	if (HasAuthority())
	{
		PlayerNumberOfKills++;
	}
}

void AMilitaryPlayerState::UpdateDeath()
{
	if (HasAuthority())
	{
		PlayerNumberOfDeaths++;	
	}
}

bool AMilitaryPlayerState::CheckKills()
{
	return PlayerNumberOfKills == KillsToEndRound;
}
