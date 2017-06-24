// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class GAME1_API SRoleAttributesWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SRoleAttributesWidget)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);
};
