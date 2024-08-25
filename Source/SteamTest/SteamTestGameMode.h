// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#pragma warning(push)
#pragma warning(disable: 4096)

#include "Steam/steam_api.h"
#pragma warning(pop)
#include "SteamTestGameMode.generated.h"
#define RAW_APP_ID "480"
UCLASS(minimalapi)
class ASteamTestGameMode : public AGameModeBase
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
public:
	ASteamTestGameMode();
	//static constexpr char* APP_ID = RAW_APP_ID;
	CSteamID MyID;

	UFUNCTION(BlueprintCallable)
	void Activate_Achievement(FName Name);
	FString Ach_Name;

};



