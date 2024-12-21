#include "Lobby/LobbyGameState.h"
#include "Lobby/LobbyPlayerController.h"
#include "Net/UnrealNetwork.h"

void ALobbyGameState::IncrementPlayerCount()
{
	if (HasAuthority())
	{
		//CurrentPlayers = CurrentPlayers + 1;
		OnLobbyStateUpdated.Broadcast();
	}
}

void ALobbyGameState::DecrementPlayerCount()
{
	if (HasAuthority())
	{
		CurrentPlayers = FMath::Max(0, CurrentPlayers - 1);
		OnLobbyStateUpdated.Broadcast();
	}
}

void ALobbyGameState::SetPlayerReady(bool bReady)
{
	if (bReady)
	{
		ReadyPlayers++;
	}
	else
	{
		ReadyPlayers = FMath::Max(0, ReadyPlayers - 1);
	}
	OnLobbyStateUpdated.Broadcast();
}

void ALobbyGameState::BeginPlay()
{
	Super::BeginPlay();
	
}

void ALobbyGameState::CheckReadyStatus()
{
	if (ReadyPlayers >= RequiredPlayers)
	{
		if (APlayerController* FirstPlayer = GetWorld()->GetFirstPlayerController())
		{
			if (ALobbyPlayerController* HostController = Cast<ALobbyPlayerController>(FirstPlayer))
			{
				HostController->ClientAllowStartGame();
			}
		}
	}
}

void ALobbyGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ALobbyGameState, CurrentPlayers);
	DOREPLIFETIME(ALobbyGameState, ReadyPlayers);
}