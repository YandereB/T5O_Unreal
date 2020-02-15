// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "NarrativePropertiesCommands.h"

#define LOCTEXT_NAMESPACE "FEditorStandaloneWindowModule"

void FNarrativePropertiesCommands::RegisterCommands()
{
	UI_COMMAND(OpenNarrativePropertiesWindow, "NarrativeProperties", "Bring up NarrativeProperties window", EUserInterfaceActionType::Button, FInputGesture());
}

#undef LOCTEXT_NAMESPACE
