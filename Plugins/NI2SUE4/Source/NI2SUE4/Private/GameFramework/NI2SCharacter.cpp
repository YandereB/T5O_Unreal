// Fill out your copyright notice in the Description page of Project Settings.


#include "NI2SCharacter.h"
#include "NI2SCharacterComponent.h"

// Sets default values
ANI2SCharacter::ANI2SCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	NI2SComponent = CreateDefaultSubobject<UNI2SCharacterComponent>("NI2SComponent");

}

// Called when the game starts or when spawned
void ANI2SCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANI2SCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ANI2SCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

