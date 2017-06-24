// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "Styling/SlateWidgetStyle.h"
#include "SlateWidgetStyleContainerBase.h"

#include "MainWidgetStyle.generated.h"

/**
 * 
 */
USTRUCT()
struct GAME1_API FMainStyle : public FSlateWidgetStyle
{
	GENERATED_USTRUCT_BODY()

	FMainStyle();
	virtual ~FMainStyle();

	// FSlateWidgetStyle
	virtual void GetResources(TArray<const FSlateBrush*>& OutBrushes) const override;
	static const FName TypeName;
	virtual const FName GetTypeName() const override { return TypeName; };
	static const FMainStyle& GetDefault();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Appearance)
		FSlateBrush TitleTextBrush;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Appearance)
		FButtonStyle ChatButtonStyle;
};

/**
 */
UCLASS(hidecategories=Object, MinimalAPI)
class UMainWidgetStyle : public USlateWidgetStyleContainerBase
{
	GENERATED_BODY()

public:
	/** The actual data describing the widget appearance. */
	UPROPERTY(Category=Appearance, EditAnywhere, meta=(ShowOnlyInnerProperties))
	FMainStyle WidgetStyle;

	virtual const struct FSlateWidgetStyle* const GetStyle() const override
	{
		return static_cast< const struct FSlateWidgetStyle* >( &WidgetStyle );
	}
};

/**  */
class FMainPanelStyleSet
{
public:

	static void Initialize();

	static void Shutdown();

	/** reloads textures used by slate renderer */
	static void ReloadTextures();

	/** @return The Slate style set for the Add Content Dialog */
	static const ISlateStyle& Get();

	static FName GetStyleSetName();

private:

	static TSharedRef< class FSlateStyleSet > Create();

private:

	static TSharedPtr< class FSlateStyleSet > AddContentDialogStyleInstance;
};