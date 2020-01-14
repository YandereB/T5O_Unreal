// Fill out your copyright notice in the Description page of Project Settings.


#include "NI2SActor.h"

// Sets default values
ANI2SActor::ANI2SActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	NI2SActorComponent = CreateDefaultSubobject<UNI2SActorComponent>("NI2SActorComponent");

}

// Called when the game starts or when spawned
void ANI2SActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANI2SActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

