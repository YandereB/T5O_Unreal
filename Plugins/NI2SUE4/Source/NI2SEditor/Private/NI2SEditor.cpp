#include "NI2SEditor.h"

//#include "NI2STargetSettingsCustomization.h"
//
//#include "Modules/ModuleInterface.h"
//#include "ISettingsModule.h"
//#include "Modules/ModuleManager.h"
//
//#include "NI2SProjectSettings.h"

#define LOCTEXT_NAMESPACE "NI2SPlugin"

DEFINE_LOG_CATEGORY(LogNI2SEditor);

void FNI2SEditorModule::StartupModule()
{
	// register settings detail panel customization
	//FPropertyEditorModule& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
	//PropertyModule.RegisterCustomClassLayout(
	//	UNI2SProjectSettings::StaticClass()->GetFName(),
	//	FOnGetDetailCustomizationInstance::CreateStatic(&FNI2STargetSettingsCustomization::MakeInstance)
	//);

	//PropertyModule.NotifyCustomizationModuleChanged();

	//ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");
	//if (SettingsModule != nullptr)
	//{
	//	SettingsModule->RegisterSettings(
	//		"Project", "Plugins", "NI2S",
	//		LOCTEXT("NI2SSettingsName", "NI2S"),
	//		LOCTEXT("NI2SSettingsDescription", "NI2S settings"),
	//		GetMutableDefault< UNI2SProjectSettings >());
	//}
}

void FNI2SEditorModule::ShutdownModule()
{
	//ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");
	//if (SettingsModule != nullptr)
	//{
	//	SettingsModule->UnregisterSettings("Project", "Plugins", "NI2S");
	//}
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FNI2SEditorModule, NI2SEditor)
