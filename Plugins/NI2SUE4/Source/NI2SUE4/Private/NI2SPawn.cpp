// Fill out your copyright notice in the Description page of Project Settings.


#include "NI2SPawn.h"
#include "NI2SPawnComponent.h"
//#include "Classes/Components/InputComponent.h"
//#include "Classes/GameFramework/FloatingPawnMovement.h"

// Sets default values
ANI2SPawn::ANI2SPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	NI2SComponent = CreateDefaultSubobject<UNI2SPawnComponent>("NI2SComponent");

	//FloatingPawnMovement = CreateDefaultSubobject<UFloatingPawnMovement>("PawnMovement");
}

// Called when the game starts or when spawned
void ANI2SPawn::BeginPlay()
{
	Super::BeginPlay();

}

//void ANI2SPawn::MoveFoward(float Amount)
//{
//	FloatingPawnMovement->AddInputVector(GetActorForwardVector() * Amount);
//}
//
//void ANI2SPawn::MoveRight(float Amount)
//{
//	FloatingPawnMovement->AddInputVector(GetActorRightVector() * Amount);
//}
//
//void ANI2SPawn::Turn(float Amount)
//{
//	AddControllerYawInput(Amount);
//}
//
//void ANI2SPawn::LookUp(float Amount)
//{
//	AddControllerPitchInput(Amount);
//}

// Called every frame
void ANI2SPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ANI2SPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//PlayerInputComponent->BindAxis("MoveFoward", this, &ANI2SPawn::MoveFoward);
	//PlayerInputComponent->BindAxis("MoveRight", this, &ANI2SPawn::MoveRight);
	//PlayerInputComponent->BindAxis("Turn", this, &ANI2SPawn::Turn);
	//PlayerInputComponent->BindAxis("LookUp", this, &ANI2SPawn::LookUp);
}

