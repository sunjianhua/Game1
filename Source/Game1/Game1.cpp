// Fill out your copyright notice in the Description page of Project Settings.

#include "Game1.h"

class FUiStudyModule : public FDefaultGameModuleImpl
{
	virtual void StartupModule() override
	{
		FSlateStyleRegistry::UnRegisterSlateStyle(FMainPanelStyleSet::GetStyleSetName());
		FMainPanelStyleSet::Initialize();
	}

	virtual void ShutdownModule() override
	{
		FMainPanelStyleSet::Shutdown();
	}
};

IMPLEMENT_PRIMARY_GAME_MODULE( FDefaultGameModuleImpl, Game1, "Game1" );
