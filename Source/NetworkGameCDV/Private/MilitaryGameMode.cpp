#include "MilitaryGameMode.h"

#include "Character/MilitaryCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Player/MilitaryPlayerController.h"

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
	if (SpawnPoints.Num() > 0)
	{
		int32 RandomIndex = FMath::RandRange(0, SpawnPoints.Num() - 1);

		AActor* SpawnPoint = SpawnPoints[RandomIndex];
		const FVector SpawnPointLocation = SpawnPoint->GetActorLocation();
		const FRotator SpawnPointRotation = SpawnPoint->GetActorRotation();

		FActorSpawnParameters ActorSpawnParameters;

		UWorld* World = GetWorld();

		AMilitaryCharacter* MilitaryCharacter = World->SpawnActor<AMilitaryCharacter>(MilitaryCharacterClass, SpawnPointLocation, SpawnPointRotation, ActorSpawnParameters);

		if (PlayerController && MilitaryCharacter)
		{
			PlayerController->Possess(MilitaryCharacter);
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Add More Spawn Points"))
	}

	
}

void AMilitaryGameMode::BeginPlay()
{
	Super::BeginPlay();

	if (SpawnPointClass)
	{
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), SpawnPointClass, SpawnPoints);
	}

}


