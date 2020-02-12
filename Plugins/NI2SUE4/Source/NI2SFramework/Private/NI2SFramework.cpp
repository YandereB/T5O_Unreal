// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "NI2SFramework.h"

#include "NI2SFrameworkSettings.h"
#include "ISettingsModule.h"
#include "ISettingsSection.h"
#include "ISettingsContainer.h"

#define LOCTEXT_NAMESPACE "NI2SPlugin"
DEFINE_LOG_CATEGORY(LogNI2SFramework);

class FNI2SFrameworkModule : public INI2SModule
{
	/** IModuleInterface implementation */
	virtual void StartupModule() override
	{
		RegisterSettings();
	}

	virtual void ShutdownModule() override
	{
		if (UObjectInitialized())
		{
			UnregisterSettings();
		}
	}

	virtual bool SupportsDynamicReloading() override
	{
		return true;
	}

private:

	// Callback for when the settings were saved.
	bool HandleSettingsSaved()
	{
		UNI2SFrameworkSettings* Settings = GetMutableDefault<UNI2SFrameworkSettings>();
		bool ResaveSettings = false;

		// You can put any validation code in here and resave the settings in case an invalid
		// value has been entered

		if (ResaveSettings)
		{
			Settings->SaveConfig();
		}

		return true;
	}

	void RegisterSettings()
	{
		// Registering some settings is just a matter of exposing the default UObject of
		// your desired class, feel free to add here all those settings you want to expose
		// to your LDs or artists.

		if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
		{
			// Create the new category
			ISettingsContainerPtr SettingsContainer = SettingsModule->GetContainer("Project");

			SettingsContainer->DescribeCategory("NI2S",
				LOCTEXT("RuntimeWDCategoryName", "NI2S"),
				LOCTEXT("RuntimeWDCategoryDescription", "Configuration for the NI2S plugin"));

			// Register the settings
			ISettingsSectionPtr SettingsSection = SettingsModule->RegisterSettings("Project", "NI2S", "Framework",
				LOCTEXT("RuntimeGeneralSettingsName", "Framework"),
				LOCTEXT("RuntimeGeneralSettingsDescription", "Framework configuration for our NI2S plugin"),
				GetMutableDefault<UNI2SFrameworkSettings>()
			);

			// Register the save handler to your settings, you might want to use it to
			// validate those or just act to settings changes.
			if (SettingsSection.IsValid())
			{
				SettingsSection->OnModified().BindRaw(this, &FNI2SFrameworkModule::HandleSettingsSaved);
			}
		}
	}

	void UnregisterSettings()
	{
		// Ensure to unregister all of your registered settings here, hot-reload would
		// otherwise yield unexpected results.

		if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
		{
			SettingsModule->UnregisterSettings("Project", "NI2S", "Framework");
		}
	}
};

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FNI2SFrameworkModule, NI2SFramework)