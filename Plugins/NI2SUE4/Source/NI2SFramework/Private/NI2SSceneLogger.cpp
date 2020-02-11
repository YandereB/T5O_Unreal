// Fill out your copyright notice in the Description page of Project Settings.

#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green,text)
#define printFString(text, fstring) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, FString::Printf(TEXT(text), fstring))
#include "NI2SSceneLogger.h"

// Sets default values
ANI2SSceneLogger::ANI2SSceneLogger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ANI2SSceneLogger::BeginPlay()
{
	Super::BeginPlay();
	
	// Standard way to log to console.
	UE_LOG(LogTemp, Warning, TEXT("joder, joder, joder"));

	// Log to Screen
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Screen Message"));

	FVector MyVector = FVector(200, 100, 900);

	// log vector
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, FString::Printf(TEXT("My Location is: %s"), *GetActorLocation().ToString()));

	// Use the shortcut defined above
	print("Hello Unreal");
	printFString("My Variable Vector is: %s", *MyVector.ToString());
}

// Called every frame
void ANI2SSceneLogger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

