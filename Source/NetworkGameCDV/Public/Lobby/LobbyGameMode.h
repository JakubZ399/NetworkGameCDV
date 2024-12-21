#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "LobbyGameMode.generated.h"

class ALobbyGameState;
/**
 * 
 */
UCLASS()
class NETWORKGAMECDV_API ALobbyGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	virtual void OnPostLogin(AController* NewPlayer) override;
	virtual void Logout(AController* Exiting) override;

	void StartGame();

private:
	void AssignHost(AController* NewHost);
};
