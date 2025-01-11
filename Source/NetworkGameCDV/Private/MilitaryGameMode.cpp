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
	if (!HasAuthority()) return;
	
	if (SpawnPoints.Num() <= 0)
	{
		return;
	}
	
	const int32 RandomIndex = FMath::RandRange(0, SpawnPoints.Num() - 1);
	AActor* SpawnPoint = SpawnPoints[RandomIndex];
	if (!SpawnPoint) return;

	UWorld* World = GetWorld();
	if (!World) return;

	AMilitaryCharacter* MilitaryCharacter = World->SpawnActor<AMilitaryCharacter>(
		MilitaryCharacterClass,
		SpawnPoint->GetActorLocation(),
		SpawnPoint->GetActorRotation()
	);

	if (PlayerController && MilitaryCharacter)
	{
		PlayerController->Possess(MilitaryCharacter);
	}
}

void AMilitaryGameMode::OnPostLogin(AController* NewPlayer)
{
	Super::OnPostLogin(NewPlayer);

	/*AMilitaryPlayerController* MilitaryController = Cast<AMilitaryPlayerController>(NewPlayer);
	if (MilitaryController && MilitaryController->IsLocalController())
	{
		MilitaryController->CreateCrosshairWidget();
	}*/
}

void AMilitaryGameMode::BeginPlay()
{
	Super::BeginPlay();

	if (SpawnPointClass)
	{
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), SpawnPointClass, SpawnPoints);
	}

}


