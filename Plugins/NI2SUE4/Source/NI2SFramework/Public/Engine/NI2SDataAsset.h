// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "NI2SDataAsset.generated.h"

USTRUCT()
struct FItemInfo {

	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere)
	FString itemName;

	//UPROPERTY(EditAnywhere)
	//UTexture2D* itemThumbnail;

	UPROPERTY(EditAnywhere)
	UBlueprint* itemBlueprint;

	UPROPERTY(EditAnywhere)
	FColor itemColor;
};

/**
 * 
 */
UCLASS(abstract)
class NI2SFRAMEWORK_API UNI2SDataAsset : public UDataAsset
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere)
	TArray<FItemInfo> items;
};