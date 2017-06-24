// Fill out your copyright notice in the Description page of Project Settings.

#include "Game1.h"
#include "Game1HUD.h"
#include "SRoleAttributesWidget.h"

void AGame1HUD::BeginPlay()
{
	Super::BeginPlay();

	RoleAttributesWidget = SNew(SRoleAttributesWidget);

	GEngine->GameViewport->AddViewportWidgetContent(SNew(SWeakWidget).PossiblyNullContent(RoleAttributesWidget.ToSharedRef()));

	RoleAttributesWidget->SetVisibility(EVisibility::Visible);
}
