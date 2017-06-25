// Fill out your copyright notice in the Description page of Project Settings.

#include "Game1.h"
#include "MainWidgetStyle.h"

class FGame1Module : public FDefaultGameModuleImpl
{
	virtual void StartupModule() override
	{
		FSlateStyleRegistry::UnRegisterSlateStyle(FMainStyleSet::GetStyleSetName());
		FMainStyleSet::Initialize();
	}

	virtual void ShutdownModule() override
	{
		FMainStyleSet::Shutdown();
	}
};

IMPLEMENT_PRIMARY_GAME_MODULE(FGame1Module, Game1, "Game1" );
