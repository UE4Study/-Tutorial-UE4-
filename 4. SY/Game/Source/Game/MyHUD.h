// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/HUD.h"
#include "MyHUD.generated.h"

/**
 * 
 */
UCLASS()
class GAME_API AMyHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	AMyHUD();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HUDFont)
		UFont* hudFont;

	virtual void DrawHUD() override;
};
