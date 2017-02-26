// Fill out your copyright notice in the Description page of Project Settings.

#include "GoldenEgg.h"
#include "MyHUD.h"

AMyHUD::AMyHUD()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AMyHUD::DrawHUD()
{
	Super::DrawHUD();

	DrawLine(200, 300, 400, 500, FLinearColor::Blue);

	DrawText(TEXT("Unreal이 여러분을 환영합니다!"), FColor::White, 0, 0, hudFont);
}


