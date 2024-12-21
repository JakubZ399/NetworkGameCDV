// Fill out your copyright notice in the Description page of Project Settings.


#include "Lobby/LobbyWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"
#include "Lobby/LobbyPlayerController.h"
#include "Lobby/LobbyGameMode.h"
#include "Lobby/LobbyGameState.h"

void ULobbyWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (ReadyButton)
	{
		ReadyButton->OnClicked.AddDynamic(this, &ULobbyWidget::OnReadyButtonClicked);
	}

	if (StartGameButton)
	{
		StartGameButton->OnClicked.AddDynamic(this, &ULobbyWidget::OnStartGameButtonClicked);
	}

	if (ALobbyGameState* LobbyGameState = GetWorld()->GetGameState<ALobbyGameState>())
	{
		LobbyGameState->OnLobbyStateUpdated.AddDynamic(this, &ULobbyWidget::OnLobbyStateChanged);
	}
}

void ULobbyWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	if (ALobbyGameState* LobbyGameState = GetWorld()->GetGameState<ALobbyGameState>())
	{
		UpdateLobbyInfo(LobbyGameState->CurrentPlayers, LobbyGameState->ReadyPlayers, LobbyGameState->RequiredPlayers);
	}

	if (ALobbyPlayerController* PC = Cast<ALobbyPlayerController>(GetOwningPlayer()))
	{
		if (PC->bIsHost && StartGameButton)
		{
			StartGameButton->SetVisibility(ESlateVisibility::Visible);
		}
	}
}


void ULobbyWidget::OnReadyButtonClicked()
{
	if (ALobbyPlayerController* PC = Cast<ALobbyPlayerController>(GetOwningPlayer()))
	{
		PC->ServerSetReady(true);
	}
}

void ULobbyWidget::OnStartGameButtonClicked()
{
	if (ALobbyPlayerController* PC = Cast<ALobbyPlayerController>(GetOwningPlayer()))
	{
		if (PC->HasAuthority())
		{
			if (ALobbyGameMode* GM = Cast<ALobbyGameMode>(UGameplayStatics::GetGameMode(this)))
			{
				GM->StartGame();
			}
		}
	}
}

void ULobbyWidget::OnLobbyStateChanged()
{
	if (ALobbyGameState* LobbyGameState = GetWorld()->GetGameState<ALobbyGameState>())
	{
		UpdateLobbyInfo(LobbyGameState->CurrentPlayers, LobbyGameState->ReadyPlayers, LobbyGameState->RequiredPlayers);
	}
}

void ULobbyWidget::UpdateLobbyInfo(int32 CurrentPlayers, int32 ReadyPlayers, int32 RequiredPlayers)
{
	if (PlayerCountText)
	{
		PlayerCountText->SetText(FText::FromString(FString::Printf(TEXT("Players: %d"), CurrentPlayers)));
	}

	if (ReadyCountText)
	{
		ReadyCountText->SetText(FText::FromString(FString::Printf(TEXT("Ready: %d/%d"), ReadyPlayers, RequiredPlayers)));
	}
}
