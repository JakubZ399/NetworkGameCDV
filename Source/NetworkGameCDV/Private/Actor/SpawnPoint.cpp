#include "Actor/SpawnPoint.h"

ASpawnPoint::ASpawnPoint()
{
	PrimaryActorTick.bCanEverTick = false;

}

void ASpawnPoint::BeginPlay()
{
	Super::BeginPlay();

	bIsAvailable = true;
}


bool ASpawnPoint::GetAvailability()
{
	return bIsAvailable;
}

void ASpawnPoint::NotAvailable(float Duration)
{
	bIsAvailable = false;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ASpawnPoint::AvailableAgain, Duration, false);
}
void ASpawnPoint::AvailableAgain()
{
	bIsAvailable = true;
}




