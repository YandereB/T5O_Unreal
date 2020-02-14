// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "NI2SActorComponent.h"
#include "NI2SPawn.generated.h"

/**
 * Base class for all Narrative-Dependent APawns
 */
UCLASS(Abstract)
class NI2SFRAMEWORK_API ANI2SPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ANI2SPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//void MoveFoward(float Amount);
	//void MoveRight(float Amount);

	//void Turn(float Amount);
	//void LookUp(float Amount);

	UPROPERTY(EditAnywhere, Category = "Narrative Simulation")
	UNI2SActorComponent* NI2SComponent;

	//class UFloatingPawnMovement* FloatingPawnMovement;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
