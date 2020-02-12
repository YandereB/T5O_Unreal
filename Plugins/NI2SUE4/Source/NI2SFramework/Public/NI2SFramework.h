// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

//General framework log
DECLARE_LOG_CATEGORY_EXTERN(LogNI2SFramework, Log, All);

class INI2SModule : public IModuleInterface
{
public:

public:

	static inline INI2SModule& Get() {
		return FModuleManager::LoadModuleChecked<INI2SModule>("NI2SFramework");
	}

	static inline bool IsAvailable() {
		return FModuleManager::Get().IsModuleLoaded("NI2SFramework");
	}
};
