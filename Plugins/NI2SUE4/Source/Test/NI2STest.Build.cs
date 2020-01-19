// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class NI2STest : ModuleRules
{
    public NI2STest(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        bEnforceIWYU = true;

        PublicDependencyModuleNames.AddRange(new string[]
        {
                "Core",
                "Engine",
                "CoreUObject",
                "Actions"
        });

        PrivateDependencyModuleNames.AddRange(new string[]
        {
        });
    }
}
