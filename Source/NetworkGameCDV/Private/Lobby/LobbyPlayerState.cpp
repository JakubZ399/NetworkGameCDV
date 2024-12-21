#include "Lobby/LobbyPlayerState.h"
#include "Lobby/LobbyGameState.h"
#include "Net/UnrealNetwork.h"

void ALobbyPlayerState::SetReady(bool bReady)
{
	if (bIsReady == bReady) return;

	bIsReady = bReady;

	if (ALobbyGameState* LobbyGameState = GetWorld()->GetGameState<ALobbyGameState>())
	{
		LobbyGameState->SetPlayerReady(bReady);
	}
}

void ALobbyPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ALobbyPlayerState, bIsReady);
}
