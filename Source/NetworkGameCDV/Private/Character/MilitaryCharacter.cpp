#include "Character/MilitaryCharacter.h"
#include "Player/MilitaryPlayerState.h"
#include "Player/MilitaryPlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Kismet/KismetSystemLibrary.h"
#include "UI/HUD/MilitaryHUD.h"


AMilitaryCharacter::AMilitaryCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AMilitaryCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	if (IsLocallyControlled())
	{
		MilitaryPlayerController = Cast<AMilitaryPlayerController>(GetController());
		if (MilitaryPlayerController)
		{
			if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(MilitaryPlayerController->GetLocalPlayer()))
			{
				Subsystem->AddMappingContext(InputMappingContext, 0);
			}
			
			FInputModeGameOnly InputModeGameOnly;
			MilitaryPlayerController->SetInputMode(InputModeGameOnly);
		}
		
		MilitaryPlayerState = GetPlayerState<AMilitaryPlayerState>();
	}
	
	Tags.AddUnique("Player");
}

void AMilitaryCharacter::Move(const FInputActionValue& Value)
{
}

void AMilitaryCharacter::SetCrosshairWidget(UCrosshairWidget* NewWidget)
{
	CrosshairWidget = NewWidget;
	if (CrosshairWidget)
	{
		SetAmmoToWidget();
	}
}

void AMilitaryCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMilitaryCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);



	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMilitaryCharacter::Move);
		//EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AMilitaryPlayerController::Look);
		//EnhancedInputComponent->BindAction(FireAction, ETriggerEvent::Triggered, this, &AMilitaryPlayerController::Fire);
		//EnhancedInputComponent->BindAction(ReloadAction, ETriggerEvent::Triggered, this, &AMilitaryPlayerController::Reload);
		//EnhancedInputComponent->BindAction(AimAction, ETriggerEvent::Triggered, this, &AMilitaryPlayerController::Aim);
		//EnhancedInputComponent->BindAction(SprintAction, ETriggerEvent::Triggered, this, &AMilitaryPlayerController::Sprint);
		//EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &AMilitaryPlayerController::Jump);
	}

}


