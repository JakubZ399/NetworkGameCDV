#include "Lobby/LobbyPlayerController.h"

#include "Blueprint/UserWidget.h"
#include "Lobby/LobbyPlayerState.h"
#include "Net/UnrealNetwork.h"

void ALobbyPlayerController::ServerSetReady_Implementation(bool bReady)
{
	if (ALobbyPlayerState* LobbyPlayerState = GetPlayerState<ALobbyPlayerState>())
	{
		if (LobbyPlayerState->bIsReady != bReady)
		{
			LobbyPlayerState->SetReady(bReady);
		}
	}
}

void ALobbyPlayerController::ClientAllowStartGame_Implementation()
{
	//UE_LOG(LogTemp, Log, TEXT("Host can start the game"));
}

void ALobbyPlayerController::SetIsHost(bool bHost)
{
	bIsHost = bHost;
}

void ALobbyPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (LobbyWidgetClass)
	{
		LobbyWidget = CreateWidget<UUserWidget>(this, LobbyWidgetClass);
		if (LobbyWidget)
		{
			LobbyWidget->AddToViewport();
		}
	}
}

void ALobbyPlayerController::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ALobbyPlayerController, bIsHost);
}
