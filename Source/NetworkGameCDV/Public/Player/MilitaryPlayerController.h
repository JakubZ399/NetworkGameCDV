// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MilitaryPlayerController.generated.h"

class AMilitaryHUD;
class AMilitaryGameMode;

UCLASS()
class NETWORKGAMECDV_API AMilitaryPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void CreateCrosshairWidget();
	virtual void OnPossess(APawn* InPawn) override;

	virtual void OnRep_Pawn() override;
	
protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	float TimeToSpawn{4};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<AMilitaryGameMode> MilitaryGameMode;
};
