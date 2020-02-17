// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

//General editor log
DECLARE_LOG_CATEGORY_EXTERN(LogNI2SEditor, Log, All);

class FMenuBuilder;

/**
* The public interface to this module
*/
class FNI2SEditorModule : public IModuleInterface
{
public:
	/** IModuleInterface implementation */
	void StartupModule();
	void ShutdownModule();

	/** This function will be bound to Command (by default it will bring up plugin window) */
	void NarrativePropertiesButtonClicked();

private:

	void AddMenuExtension(FMenuBuilder& Builder);

	TSharedRef<class SDockTab> OnSpawnPluginTab(const class FSpawnTabArgs& SpawnTabArgs);

private:
	TSharedPtr<class FUICommandList> PluginCommands;
};
