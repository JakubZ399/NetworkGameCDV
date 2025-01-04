// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/MilitaryCharacter.h"

// Sets default values
AMilitaryCharacter::AMilitaryCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMilitaryCharacter::BeginPlay()
{
	Super::BeginPlay();

	Tags.AddUnique("Player");
	
}

// Called every frame
void AMilitaryCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMilitaryCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

