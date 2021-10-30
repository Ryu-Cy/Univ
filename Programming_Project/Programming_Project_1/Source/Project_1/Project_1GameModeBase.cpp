// Copyright Epic Games, Inc. All Rights Reserved.


#include "Project_1GameModeBase.h"
#include "MyPlayer.h"

AProject_1GameModeBase::AProject_1GameModeBase() {
	DefaultPawnClass = AMyPlayer::StaticClass();
}