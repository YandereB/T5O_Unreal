// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "NarrativePropertiesStyle.h"

class FNarrativePropertiesCommands : public TCommands<FNarrativePropertiesCommands>
{
public:

	FNarrativePropertiesCommands()
		: TCommands<FNarrativePropertiesCommands>(TEXT("NarrativeProperties"), NSLOCTEXT("Contexts", "NarrativeProperties", "NarrativeProperties Plugin"), NAME_None, FNarrativePropertiesStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > OpenNarrativePropertiesWindow;
};