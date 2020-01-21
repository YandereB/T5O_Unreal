// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NI2SActorComponent.h"
#include "NI2SActor.generated.h"

/**
 * Base class for all Narrative-Dependent AActors
 */
UCLASS(abstract)
class NI2SFRAMEWORK_API ANI2SActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ANI2SActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Narrative Simulation")
	UNI2SActorComponent* NI2SComponent;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
