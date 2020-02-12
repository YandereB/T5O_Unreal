// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "NI2SFrameworkSettings.generated.h"

/**
 *
 */
UCLASS(config = Game, defaultconfig)
class NI2SFRAMEWORK_API UNI2SFrameworkSettings : public UObject
{
	GENERATED_BODY()

public:
	UNI2SFrameworkSettings(const FObjectInitializer& ObjectInitializer);

	/** Sample bool property */
	UPROPERTY(EditAnywhere, config, Category = NarrativeEngine)
		bool bUseSceneDirector;

	/** Sample string list */
	UPROPERTY(config, EditAnywhere, Category = NarrativeEngine, meta = (ConfigRestartRequired = true))
		TArray<FString> NarrativeNodes;
};
