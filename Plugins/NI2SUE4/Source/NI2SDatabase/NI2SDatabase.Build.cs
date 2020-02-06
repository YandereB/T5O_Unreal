// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class NI2SDatabase : ModuleRules
{
    public NI2SDatabase(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        bEnforceIWYU = true;

        PublicDependencyModuleNames.AddRange(new string[]
        {
            "Core",
            "DatabaseSupport",
            "RemoteDatabaseSupport"
        });

        PrivateDependencyModuleNames.AddRange(new string[]
        {
            "Sockets"
        });
    }
}
