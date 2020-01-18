// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CharacterProfile.h"

/**
 * 
 */
class NI2SUE4_API CharacterSheetBase
{
public:
	CharacterSheetBase();
	~CharacterSheetBase();

protected:
	CharacterProfile* Profile;

	CharacterProfile* GetProfile();
	void SetProfile(CharacterProfile* profile);
};
