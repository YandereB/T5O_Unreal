// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class NI2SEditor : ModuleRules
{
#if WITH_FORWARDED_MODULE_RULES_CTOR
    public NI2SEditor(ReadOnlyTargetRules Target) : base(Target)
#else
    public NI2SEditor(TargetInfo Target)
#endif
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "CoreUObject",
                "Engine",
                "RenderCore",
                "RHI",
                "Slate",
                "SlateCore",
                "EditorStyle",
                "EditorWidgets",
                "DesktopWidgets",
                "PropertyEditor",
                "SharedSettingsWidgets",
                "SourceControl",
                "UnrealEd",
                "Http",
                "Json",
                "JsonUtilities",
                "LevelEditor",
                "Projects",
                "InputCore"
            }
            );


        DynamicallyLoadedModuleNames.AddRange(
            new string[]
            {
                    "Settings"
            }
            );

        PublicIncludePathModuleNames.AddRange(
            new string[]
            {
                    "Settings"
            }
            );
    }
}
