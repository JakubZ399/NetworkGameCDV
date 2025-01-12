#include "MilitaryGameMode.h"

#include "Actor/SpawnPoint.h"
#include "Character/MilitaryCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Player/MilitaryPlayerController.h"

void AMilitaryGameMode::BeginPlay()
{
	Super::BeginPlay();

	if (SpawnPointClass)
	{
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), SpawnPointClass, SpawnPoints);
	}

}

void AMilitaryGameMode::BackToLobby()
{
	if (HasAuthority())
	{
		UWorld* World = GetWorld();
		if (World)
		{
			for (FConstPlayerControllerIterator Iterator = World->GetPlayerControllerIterator(); Iterator; ++Iterator)
			{
				APlayerController* PlayerController = Iterator->Get();
				if (PlayerController && PlayerController->IsLocalController() == false) // Ensure this is a client
				{
					PlayerController->ClientTravel(TEXT("/Game/Level/Lobby"), TRAVEL_Absolute);
				}
			}
			World->ServerTravel(TEXT("/Game/Level/Lobby"));
		}
	}
}



void AMilitaryGameMode::RespawnPlayer(AMilitaryPlayerController* PlayerController)
{
	if (!HasAuthority()) return;
	
	if (SpawnPoints.Num() <= 0)
	{
		return;
	}

	const int32 MaxAttempts = 15;
	int32 AttemptCount = 0;

	while (AttemptCount < MaxAttempts)
	{
		const int32 RandomIndex = FMath::RandRange(0, SpawnPoints.Num() - 1);
		AActor* SpawnPointActor = SpawnPoints[RandomIndex];
		
		if (!SpawnPointActor) return;

		ASpawnPoint* SpawnPoint = Cast<ASpawnPoint>(SpawnPointActor);

		if (SpawnPoint && SpawnPoint->GetAvailability())
		{
			SpawnPlayerCharacter(PlayerController, SpawnPointActor);
			SpawnPoint->NotAvailable(SpawnPointDuration);
			return;
		}

		AttemptCount++;
	}

	/*UWorld* World = GetWorld();
	if (!World) return;

	AMilitaryCharacter* MilitaryCharacter = World->SpawnActor<AMilitaryCharacter>(
		MilitaryCharacterClass,
		SpawnPointActor->GetActorLocation(),
		SpawnPointActor->GetActorRotation()
	);

	if (PlayerController && MilitaryCharacter)
	{
		PlayerController->Possess(MilitaryCharacter);
	}*/
}

void AMilitaryGameMode::SpawnPlayerCharacter(AMilitaryPlayerController* PlayerController, const AActor* SpawnPointActor) const
{
	UWorld* World = GetWorld();
	if (!World)
	{
		return;
	}

	AMilitaryCharacter* MilitaryCharacter = World->SpawnActor<AMilitaryCharacter>(
		MilitaryCharacterClass,
		SpawnPointActor->GetActorLocation(),
		SpawnPointActor->GetActorRotation()
	);

	if (PlayerController && MilitaryCharacter)
	{
		PlayerController->Possess(MilitaryCharacter);
	}
}


