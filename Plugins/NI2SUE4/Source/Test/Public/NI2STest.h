// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"

/**
* The public interface to this module
*/
class FNI2STest : public IModuleInterface
{
public:

	virtual void StartupModule() override {}
	virtual void ShutdownModule() override {}

	static inline FNI2STest& Get() {
		return FModuleManager::LoadModuleChecked<FNI2STest>("NI2STest");
	}

	static inline bool IsAvailable() {
		return FModuleManager::Get().IsModuleLoaded("NI2STest");
	}
};

IMPLEMENT_MODULE(FNI2STest, NI2STest);
