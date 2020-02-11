#include "NI2SDatabase.h"
#include "NI2SDatabaseConnection.h"

#include "NI2SDatabaseSettings.h"
#include "ISettingsModule.h"
#include "ISettingsSection.h"
#include "ISettingsContainer.h"

#define LOCTEXT_NAMESPACE "NI2SDatabase"
DEFINE_LOG_CATEGORY_STATIC(LogNI2SDatabase, Log, All);

class FNI2SDatabase : public INI2SDatabase
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

	/** IADOSupport implementation */
	virtual FNI2SDatabaseConnection* CreateInstance() const override;

private:

	// Callback for when the settings were saved.
	bool HandleSettingsSaved()
	{
		UNI2SDatabaseSettings* Settings = GetMutableDefault<UNI2SDatabaseSettings>();
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
			ISettingsSectionPtr SettingsSection = SettingsModule->RegisterSettings("Project", "NI2S", "Database",
				LOCTEXT("RuntimeGeneralSettingsName", "Database"),
				LOCTEXT("RuntimeGeneralSettingsDescription", "Database configuration for our NI2S plugin"),
				GetMutableDefault<UNI2SDatabaseSettings>()
			);

			// Register the save handler to your settings, you might want to use it to
			// validate those or just act to settings changes.
			if (SettingsSection.IsValid())
			{
				SettingsSection->OnModified().BindRaw(this, &FNI2SDatabase::HandleSettingsSaved);
			}
		}
	}

	void UnregisterSettings()
	{
		// Ensure to unregister all of your registered settings here, hot-reload would
		// otherwise yield unexpected results.

		if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
		{
			SettingsModule->UnregisterSettings("Project", "CustomSettings", "General");
		}
	}
};

IMPLEMENT_MODULE(FNI2SDatabase, NI2SDatabase);

FNI2SDatabaseConnection* FNI2SDatabase::CreateInstance() const
{
	return new FNI2SDatabaseConnection();
}
