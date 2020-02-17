// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "NI2SFrameworkBPFunctionLibrary.generated.h"

USTRUCT(BlueprintType)
struct NI2SFRAMEWORK_API FNI2SInitParams
{
	GENERATED_BODY()

	UPROPERTY()
	bool bIsSceneServer;
};

/**
 * 
 */
UCLASS()
class NI2SFRAMEWORK_API UNI2SFrameworkBPFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Execute Sample function", Keywords = "BlueprinfFunctionLibrary sample test testing"), Category = "BlueprinfFunctionLibraryTesting")
	static float BlueprinfFunctionLibrarySampleFunction(float Param);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Initialize Narrative Engine", Keywords = "NI2S narrative init"), Category = "Narrative Engine")
	static bool InitializeNarrativeEngine(FNI2SInitParams InitParams);
};
