#include "Player/MilitaryPlayerController.h"

#include "MilitaryGameMode.h"
#include "Kismet/GameplayStatics.h"


void AMilitaryPlayerController::BeginPlay()
{
	Super::BeginPlay();

	MilitaryGameMode = Cast<AMilitaryGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
}
