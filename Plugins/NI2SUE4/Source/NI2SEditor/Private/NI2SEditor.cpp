#include "NI2SEditor.h"
#include "NarrativeEdMode.h"
#include "NarrativePropertiesStyle.h"
#include "NarrativePropertiesCommands.h"
#include "LevelEditor.h"
#include "Widgets/Docking/SDockTab.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Text/STextBlock.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"

static const FName NarrativePropertiesTabName("NarrativeProperties");

#define LOCTEXT_NAMESPACE "NI2SPlugin"

DEFINE_LOG_CATEGORY(LogNI2SEditor);

void FNI2SEditorModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	FEditorModeRegistry::Get().RegisterMode<FNarrativeEdMode>(FNarrativeEdMode::EM_NarrativeEdModeId,
		LOCTEXT("NarrativeEdModeName", "Narrative Editing"),
		FSlateIcon(),
		true);
	
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	FNarrativePropertiesStyle::Initialize();
	FNarrativePropertiesStyle::ReloadTextures();

	FNarrativePropertiesCommands::Register();

	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FNarrativePropertiesCommands::Get().OpenNarrativePropertiesWindow,
		FExecuteAction::CreateRaw(this, &FNI2SEditorModule::NarrativePropertiesButtonClicked),
		FCanExecuteAction());

	FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
	{
		TSharedPtr<FExtender> MenuExtender = MakeShareable(new FExtender());
		MenuExtender->AddMenuExtension("WindowLayout",
			EExtensionHook::After,
			PluginCommands,
			FMenuExtensionDelegate::CreateRaw(this, &FNI2SEditorModule::AddMenuExtension));

		LevelEditorModule.GetMenuExtensibilityManager()->AddExtender(MenuExtender);
	}

	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(NarrativePropertiesTabName, FOnSpawnTab::CreateRaw(this, &FNI2SEditorModule::OnSpawnPluginTab))
		.SetDisplayName(LOCTEXT("FNarrativePropertiesTabTitle", "Narrative Properties"))
		.SetMenuType(ETabSpawnerMenuType::Hidden);
}

void FNI2SEditorModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	FEditorModeRegistry::Get().UnregisterMode(FNarrativeEdMode::EM_NarrativeEdModeId);

	FNarrativePropertiesStyle::Shutdown();

	FNarrativePropertiesCommands::Unregister();

	FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(NarrativePropertiesTabName);
}

void FNI2SEditorModule::NarrativePropertiesButtonClicked()
{
	FGlobalTabmanager::Get()->InvokeTab(NarrativePropertiesTabName);
}

void FNI2SEditorModule::AddMenuExtension(FMenuBuilder& Builder)
{
	Builder.AddMenuEntry(FNarrativePropertiesCommands::Get().OpenNarrativePropertiesWindow);
}

TSharedRef<class SDockTab> FNI2SEditorModule::OnSpawnPluginTab(const FSpawnTabArgs& SpawnTabArgs)
{
	FText WidgetText = FText::Format(LOCTEXT("WindowWidgetText", "Add code to {0} in {1} to override this window's contents"),
		FText::FromString(TEXT("FNI2SEditorModule::OnSpawnPluginTab")),
		FText::FromString(TEXT("NI2SEditor.cpp"))
	);

	return SNew(SDockTab).TabRole(ETabRole::NomadTab)
		[
			// Put your tab content here!
			SNew(SBox).HAlign(HAlign_Center).VAlign(VAlign_Center)
			[
				SNew(STextBlock).Text(WidgetText)
			]
		];
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FNI2SEditorModule, NI2SEditor)
