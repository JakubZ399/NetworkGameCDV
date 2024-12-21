// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LobbyWidget.generated.h"

/**
 * 
 */
UCLASS()
class NETWORKGAMECDV_API ULobbyWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

	UPROPERTY(meta = (BindWidget))
	class UButton* ReadyButton;

	UPROPERTY(meta = (BindWidget))
	UButton* StartGameButton;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* PlayerCountText;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* ReadyCountText;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* ReadyPlayersText;

	UFUNCTION()
	void OnReadyButtonClicked();

	UFUNCTION()
	void OnStartGameButtonClicked();

	UFUNCTION()
	void OnLobbyStateChanged();

	void UpdateLobbyInfo(int32 CurrentPlayers, int32 ReadyPlayers, int32 RequiredPlayers);
};
