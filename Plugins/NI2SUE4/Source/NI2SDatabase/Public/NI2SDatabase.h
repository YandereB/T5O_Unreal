// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"

class FNI2SDatabaseConnection;

/**
* The public interface to this module
*/
class INI2SDatabase : public IModuleInterface
{
public:

	static inline INI2SDatabase& Get() {
		return FModuleManager::LoadModuleChecked<INI2SDatabase>("NI2SDatabase");
	}

	static inline bool IsAvailable() {
		return FModuleManager::Get().IsModuleLoaded("NI2SDatabase");
	}

	/**
	 * Function to create a database connection object.
	 */
	virtual FNI2SDatabaseConnection* CreateInstance() const = 0;
};