// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/HUD.h"
#include "Game1HUD.generated.h"

/**
 * 
 */
UCLASS()
class GAME1_API AGame1HUD : public AHUD
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;

protected:
	TSharedPtr<class SRoleAttributesWidget> RoleAttributesWidget;
};
