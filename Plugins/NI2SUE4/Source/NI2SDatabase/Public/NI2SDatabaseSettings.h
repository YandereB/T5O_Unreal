// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "NI2SDatabaseSettings.generated.h"

/**
 * 
 */
UCLASS(config = Game, defaultconfig)
class NI2SDATABASE_API UNI2SDatabaseSettings : public UObject
{
	GENERATED_BODY()
	
public:
	UNI2SDatabaseSettings(const FObjectInitializer& ObjectInitializer);

	/** Sample bool property */
	UPROPERTY(EditAnywhere, config, Category = ConnectionSettings, meta = (ConfigRestartRequired = true))
	bool bUseRemote;

	/** Sample string list */
	UPROPERTY(config, EditAnywhere, Category = ConnectionSettings, meta = (ConfigRestartRequired = true))
	FString ConnectionString;

	/** Sample bool property */
	UPROPERTY(EditAnywhere, config, Category = CommonSettings)
	bool bIsDebugDatabase;

	UPROPERTY(EditAnywhere, config, Category = CommonSettings)
	bool bCommonSettingsPlaceholder;
};
