// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"

//General editor log
DECLARE_LOG_CATEGORY_EXTERN(LogNI2SEditor, Log, All);

/**
* The public interface to this module
*/
class FNI2SEditorModule : public IModuleInterface
{
	/*public:

		static inline FNI2SEditor& Get()
		{
			return FModuleManager::LoadModuleChecked< FNI2SEditor >("NI2SEditor");
		}*/

public:
	/** IModuleInterface implementation */
	void StartupModule();
	void ShutdownModule();
};
