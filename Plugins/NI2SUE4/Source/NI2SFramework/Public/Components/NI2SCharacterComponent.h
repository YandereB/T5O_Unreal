// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NI2SActorComponent.h"
//#include "CharacterSheetBase.h"
#include "NI2SCharacterComponent.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class NI2SFRAMEWORK_API UNI2SCharacterComponent : public UNI2SActorComponent
{
	GENERATED_BODY()
	
//public:
	//UPROPERTY(EditAnywhere, Category = Narrative, Replicated, meta = (DisplayName = "Character Sheet"))
	//CharacterSheetBase* CharacterSheet;
};
