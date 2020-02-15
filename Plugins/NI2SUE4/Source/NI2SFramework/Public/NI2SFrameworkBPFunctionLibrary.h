// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "NI2SFrameworkBPFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class NI2SFRAMEWORK_API UNI2SFrameworkBPFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Execute Sample function", Keywords = "BlueprinfFunctionLibrary sample test testing"), Category = "BlueprinfFunctionLibraryTesting")
	static float BlueprinfFunctionLibrarySampleFunction(float Param);
};
