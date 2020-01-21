// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "NI2SActorComponent.h"
#include "NI2SCharacter.generated.h"

/**
 * Base class for all Narrative-Dependent ACharacters
 */
UCLASS(abstract)
class NI2SFRAMEWORK_API ANI2SCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ANI2SCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Narrative Simulation")
	UNI2SActorComponent* NI2SComponent;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
