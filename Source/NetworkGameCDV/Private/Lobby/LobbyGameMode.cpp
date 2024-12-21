#include "Lobby/LobbyGameMode.h"
#include "Lobby/LobbyGameState.h"
#include "Lobby/LobbyPlayerController.h"
#include "GameFramework/PlayerController.h"

void ALobbyGameMode::OnPostLogin(AController* NewPlayer)
{
	Super::OnPostLogin(NewPlayer);
	
	if (APlayerController* PlayerController = Cast<APlayerController>(NewPlayer))
	{
		if (GetWorld()->GetFirstPlayerController() == PlayerController)
		{
			AssignHost(NewPlayer);
		}
	}
	
	if (HasAuthority())
	{
		if (ALobbyGameState* LobbyGameState = GetGameState<ALobbyGameState>())
		{
			LobbyGameState->IncrementPlayerCount();
			GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Cyan, "Player joined");
		}
	}
}

void ALobbyGameMode::Logout(AController* Exiting)
{
	Super::Logout(Exiting);
	
	if (ALobbyGameState* LobbyGameState = GetGameState<ALobbyGameState>())
	{
		LobbyGameState->DecrementPlayerCount();
	}
}

void ALobbyGameMode::StartGame()
{
	if (HasAuthority())
	{
		if (ALobbyGameState* LobbyGameState = GetGameState<ALobbyGameState>())
		{
			if (LobbyGameState->ReadyPlayers >= LobbyGameState->RequiredPlayers)
			{
				UWorld* World = GetWorld();
				if (World)
				{
					World->ServerTravel(TEXT("/Game/Level/DemoMap"));
				}
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("Not enough players ready to start the game."));
			}
		}
	}
}

void ALobbyGameMode::AssignHost(AController* NewHost)
{
	if (APlayerController* PlayerController = Cast<APlayerController>(NewHost))
	{
		if (ALobbyPlayerController* HostController = Cast<ALobbyPlayerController>(PlayerController))
		{
			HostController->SetIsHost(true);
		}
	}
}
