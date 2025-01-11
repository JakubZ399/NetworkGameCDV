// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "MilitaryGameMode.generated.h"

class AMilitaryCharacter;
class ASpawnPoint;
class AMilitaryPlayerController;
/**
 * 
 */
UCLASS()
class NETWORKGAMECDV_API AMilitaryGameMode : public AGameMode
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	void BackToLobby();

	UFUNCTION(BlueprintCallable)
	void RespawnPlayer(AMilitaryPlayerController* PlayerController);

	virtual void OnPostLogin(AController* NewPlayer) override;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TArray<AActor*> SpawnPoints;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AActor> SpawnPointClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AMilitaryCharacter> MilitaryCharacterClass;
	
};
