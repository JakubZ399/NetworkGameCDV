// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnPoint.generated.h"

UCLASS()
class NETWORKGAMECDV_API ASpawnPoint : public AActor
{
	GENERATED_BODY()
	
public:	
	ASpawnPoint();
	bool GetAvailability();
	void NotAvailable(float Duration);

protected:
	virtual void BeginPlay() override;

private:
	bool bIsAvailable{true};

	FTimerHandle TimerHandle;

	void AvailableAgain();
	

};
