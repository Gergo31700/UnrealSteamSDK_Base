// Copyright Epic Games, Inc. All Rights Reserved.

#include "SteamTestGameMode.h"
#include "SteamTestCharacter.h"
#include "UObject/ConstructorHelpers.h"

void ASteamTestGameMode::BeginPlay()
{
	Super::BeginPlay();
	FFileHelper::SaveStringToFile(TEXT(RAW_APP_ID), TEXT("steam_appid.txt"));
	SteamAPI_RestartAppIfNecessary(atoi("480"));
	if (SteamAPI_Init())
	{
		MyID = SteamUser()->GetSteamID(); // UserID, Use to call steam related functions, unlock achivements etc
		//SteamUserStats()->ResetAllStats(true); Reset all stats
		SteamUserStats()->ClearAchievement("ACH_WIN_ONE_GAME"); //Reset Achievement
		
		
	}

}

void ASteamTestGameMode::Activate_Achievement(FName Name)
{
	


	if (SteamAPI_Init()) //Fire up and connect to the steam api, if its succesfull we will trigger functions from it
	{
		 
		FString NameString = Name.ToString();
		const char* NameChar = TCHAR_TO_UTF8(*NameString); //Convert string to char



		
		SteamUserStats()->ResetAllStats(true);
		SteamUserStats()->ClearAchievement(NameChar);

		SteamUserStats()->SetAchievement(NameChar);
		SteamUserStats()->StoreStats();
	}

	
	
	

}

ASteamTestGameMode::ASteamTestGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

}
