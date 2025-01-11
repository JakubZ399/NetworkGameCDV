#include "Player/MilitaryPlayerController.h"
#include "MilitaryGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "UI/HUD/MilitaryHUD.h"


void AMilitaryPlayerController::CreateCrosshairWidget()
{
	TObjectPtr<AMilitaryHUD> MilitaryHUD = Cast<AMilitaryHUD>(GetHUD());
	MilitaryHUD->ResetCrosshairWidget();
	MilitaryHUD->WidgetSetup();
}

void AMilitaryPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	MilitaryGameMode = Cast<AMilitaryGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
}


