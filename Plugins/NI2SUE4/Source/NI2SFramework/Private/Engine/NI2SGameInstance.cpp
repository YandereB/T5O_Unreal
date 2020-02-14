// Fill out your copyright notice in the Description page of Project Settings.

#include "NI2SGameInstance.h"
#include "SceneManager/NI2SSceneManager.h"

// Singleton-like accessor. I only use this as a workaround for PIE
 // The GameInstance lifecycle is different in PIE
 // In proper builds, this wouldn't be necessary (I'll explain this further down)
UNI2SSceneManager* UNI2SGameInstance::SceneManager()
{
    return
        IsValid(SceneManagerInstance) ?
        SceneManagerInstance :
        SceneManagerInstance = NewObject<UNI2SSceneManager>(this, FName("SceneManager"));
}

// Cleanup. This acts as a quasi-destructor
void UNI2SGameInstance::Shutdown()
{
    // Important, if you overwrite functionality in UE4.
    // Omitting this, may cause errors (depending on the class).
    Super::Shutdown();

    // PIE may cause this to be invalid. During the game, it will always be valid
    if (IsValid(SceneManagerInstance))
    {
        //Do SceneManagerInstance Cleanup
        //SceneManagerInstance->ClearStoredActors();
        //SceneManagerInstance->ClearLevelStorage();
        //ClearPlayerInventoryCache();
    }
}