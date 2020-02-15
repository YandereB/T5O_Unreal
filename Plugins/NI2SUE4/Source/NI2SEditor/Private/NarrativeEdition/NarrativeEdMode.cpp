// Fill out your copyright notice in the Description page of Project Settings.


#include "NarrativeEdMode.h"
#include "NarrativeEdModeToolkit.h"
#include "Toolkits/ToolkitManager.h"
#include "EditorModeManager.h"

const FEditorModeID FNarrativeEdMode::EM_NarrativeEdModeId = TEXT("EM_NarrativeEdMode");

FNarrativeEdMode::FNarrativeEdMode()
{

}

FNarrativeEdMode::~FNarrativeEdMode()
{

}

void FNarrativeEdMode::Enter()
{
	FEdMode::Enter();

	if (!Toolkit.IsValid() && UsesToolkits())
	{
		Toolkit = MakeShareable(new FNarrativeEdModeToolkit);
		Toolkit->Init(Owner->GetToolkitHost());
	}
}

void FNarrativeEdMode::Exit()
{
	if (Toolkit.IsValid())
	{
		FToolkitManager::Get().CloseToolkit(Toolkit.ToSharedRef());
		Toolkit.Reset();
	}

	// Call base Exit method to ensure proper cleanup
	FEdMode::Exit();
}

bool FNarrativeEdMode::UsesToolkits() const
{
	return true;
}