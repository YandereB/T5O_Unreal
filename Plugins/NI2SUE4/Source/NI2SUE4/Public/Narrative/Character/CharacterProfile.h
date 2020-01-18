// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProfileStat.h"

/**
 * 
 */
class NI2SUE4_API CharacterProfile
{
public:
	CharacterProfile();
	CharacterProfile(ProfileStat stats[]);
	~CharacterProfile();

private:
	ProfileStat* Stats[];
};
