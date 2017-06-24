// Fill out your copyright notice in the Description page of Project Settings.

#include "Game1.h"
#include "MainWidgetStyle.h"


FMainStyle::FMainStyle()
{}

FMainStyle::~FMainStyle()
{}

const FName FMainStyle::TypeName(TEXT("FMainStyle"));

const FMainStyle& FMainStyle::GetDefault()
{
	static FMainStyle Default;
	return Default;
}

void FMainStyle::GetResources(TArray<const FSlateBrush*>& OutBrushes) const
{}

/**
*
*/
TSharedPtr< class FSlateStyleSet > FMainPanelStyleSet::AddContentDialogStyleInstance = NULL;

void FMainPanelStyleSet::Initialize()
{
	if (!AddContentDialogStyleInstance.IsValid())
	{
		AddContentDialogStyleInstance = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*AddContentDialogStyleInstance);
	}
}

void FMainPanelStyleSet::Shutdown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*AddContentDialogStyleInstance);
	ensure(AddContentDialogStyleInstance.IsUnique());
	AddContentDialogStyleInstance.Reset();
}

void FMainPanelStyleSet::ReloadTextures()
{
	FSlateApplication::Get().GetRenderer()->ReloadTextureResources();
}

const ISlateStyle& FMainPanelStyleSet::Get()
{
	return *AddContentDialogStyleInstance;
}

FName FMainPanelStyleSet::GetStyleSetName()
{
	static FName StyleSetName(TEXT("MainPanelStyle"));
	return StyleSetName;
}

TSharedRef< class FSlateStyleSet > FMainPanelStyleSet::Create()
{
	TSharedRef<FSlateStyleSet> StyleRef = FSlateGameResources::New(FMainPanelStyleSet::GetStyleSetName(), "/Game/UI/Styles", "/Game/UI/Styles");
	return StyleRef;
}
