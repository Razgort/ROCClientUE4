// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "ROCClient.h"
#include "ROCClientGameMode.h"
#include "ROCClientHUD.h"
#include "ROCClientCharacter.h"

AROCClientGameMode::AROCClientGameMode(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AROCClientHUD::StaticClass();
}
