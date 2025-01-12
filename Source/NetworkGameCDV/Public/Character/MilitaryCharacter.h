// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MilitaryCharacter.generated.h"

class AMilitaryPlayerState;
class AMilitaryHUD;
class UCrosshairWidget;
class AMilitaryPlayerController;
class UInputMappingContext;
class UInputAction;

UCLASS()
class NETWORKGAMECDV_API AMilitaryCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AMilitaryCharacter();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	void SetCrosshairWidget(UCrosshairWidget* NewWidget);

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	UInputMappingContext* InputMappingContext;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	UInputAction* MoveAction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	UInputAction* LookAction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	UInputAction* FireAction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	UInputAction* ReloadAction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	UInputAction* AimAction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	UInputAction* SprintAction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	UInputAction* JumpAction;

	// Input handlers
	/*UFUNCTION(BlueprintCallable)
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void Fire();
	void Reload();
	void Aim(const FInputActionValue& Value);
	void Sprint(const FInputActionValue& Value);*/

	UPROPERTY(BlueprintReadOnly)
	AMilitaryPlayerController* MilitaryPlayerController;

	UPROPERTY(BlueprintReadOnly)
	AMilitaryPlayerState* MilitaryPlayerState;

	UPROPERTY(BlueprintReadWrite)
	UCrosshairWidget* CrosshairWidget;

	UPROPERTY(BlueprintReadOnly)
	AMilitaryHUD* MilitaryHUD;

	UFUNCTION(BlueprintImplementableEvent)
	void SetAmmoToWidget();

};
