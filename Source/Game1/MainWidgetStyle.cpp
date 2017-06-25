// Fill out your copyright notice in the Description page of Project Settings.

#include "Game1.h"
#include "MainWidgetStyle.h"
#include "Slate/SlateGameResources.h"

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
TSharedPtr< class FSlateStyleSet > FMainStyleSet::AddContentDialogStyleInstance = NULL;

void FMainStyleSet::Initialize()
{
	if (!AddContentDialogStyleInstance.IsValid())
	{
		AddContentDialogStyleInstance = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*AddContentDialogStyleInstance);
	}
}

void FMainStyleSet::Shutdown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*AddContentDialogStyleInstance);
	ensure(AddContentDialogStyleInstance.IsUnique());
	AddContentDialogStyleInstance.Reset();
}

void FMainStyleSet::ReloadTextures()
{
	FSlateApplication::Get().GetRenderer()->ReloadTextureResources();
}

const ISlateStyle& FMainStyleSet::Get()
{
	return *AddContentDialogStyleInstance;
}

FName FMainStyleSet::GetStyleSetName()
{
	static FName StyleSetName(TEXT("MainStyleSet"));
	return StyleSetName;
}

TSharedRef< class FSlateStyleSet > FMainStyleSet::Create()
{
	TSharedRef<FSlateStyleSet> StyleRef = FSlateGameResources::New(FMainStyleSet::GetStyleSetName(), "/Game/UI/Styles", "/Game/UI/Styles");
	return StyleRef;
}
