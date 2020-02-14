// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "NI2SGameInstance.generated.h"

class UNI2SSceneManager;

/**
 * 
 */
UCLASS(Abstract)
class NI2SFRAMEWORK_API UNI2SGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
    // Accessor for C++ & BP. Should be self-explanatory
    UFUNCTION(BlueprintPure, Category = "NI2S", meta = (DisplayName = "Get Scene Manager", Keywords = "SceneManager"))
    UNI2SSceneManager* SceneManager();

protected:
    // This is where we will clean up, as the game is shut down
    virtual void Shutdown() override;


private:
    // Needs to be an UPROPERTY(), so the GC does its thing
    // Transient, so it doesn't get serialized itself. Will be nulled when the
    // game starts. Initialization happens later by hand.
    UPROPERTY(Transient)
    UNI2SSceneManager* SceneManagerInstance;
};
