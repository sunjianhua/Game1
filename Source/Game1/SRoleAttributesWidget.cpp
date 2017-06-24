// Fill out your copyright notice in the Description page of Project Settings.

#include "Game1.h"
#include "SRoleAttributesWidget.h"
#include "SlateOptMacros.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SRoleAttributesWidget::Construct(const FArguments& InArgs)
{
	ChildSlot
	[
		SNew(STextBlock).Text(FText::FromString("user name"))
	];
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
