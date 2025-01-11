#include "Player/MilitaryPlayerController.h"
#include "MilitaryGameMode.h"
#include "Character/MilitaryCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "UI/HUD/MilitaryHUD.h"


void AMilitaryPlayerController::CreateCrosshairWidget()
{
	if (!IsLocalController())
	{
		return;
	}
	
	AMilitaryHUD* MilitaryHUD = Cast<AMilitaryHUD>(GetHUD());
	if (MilitaryHUD)
	{
		MilitaryHUD->ResetCrosshairWidget();
		
		UCrosshairWidget* NewWidget = MilitaryHUD->WidgetSetup();
		
		AMilitaryCharacter* MilitaryCharacter = Cast<AMilitaryCharacter>(GetPawn());
		if (MilitaryCharacter && NewWidget)
		{
			MilitaryCharacter->SetCrosshairWidget(NewWidget);
		}
	}
}

void AMilitaryPlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	if (IsLocalController())
	{
		CreateCrosshairWidget();
	}
	
}

void AMilitaryPlayerController::OnRep_Pawn()
{
	Super::OnRep_Pawn();

	if (IsLocalController())
	{
		CreateCrosshairWidget();
	}
}

void AMilitaryPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	MilitaryGameMode = Cast<AMilitaryGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
}


