// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterSheetBase.h"

CharacterSheetBase::CharacterSheetBase()
{
	Profile = new CharacterProfile();
}

CharacterSheetBase::~CharacterSheetBase()
{
}

CharacterProfile* CharacterSheetBase::GetProfile()
{
	return Profile;
}

void CharacterSheetBase::SetProfile(CharacterProfile* profile)
{
	Profile = profile;
}
