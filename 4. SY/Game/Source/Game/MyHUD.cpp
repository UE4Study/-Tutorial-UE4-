// Fill out your copyright notice in the Description page of Project Settings.

#include "Game.h"
#include "MyHUD.h"
#include "GameGameModeBase.h"
#include "MyCharacter.h"
#include "Monster.h"

AMyHUD::AMyHUD()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AMyHUD::DrawHUD()
{
	Super::DrawHUD();

	AGameGameModeBase* GameMode = Cast<AGameGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	if (!GameMode)
		return;

	EPlayState playState = GameMode->GetCurrentState();
	switch (playState)
	{
	case EPlayState::EPS_Play:
	{
		DrawText(TEXT("Play"), FColor::Black, 100, 0, hudFont);
		AMyCharacter* MyCharacter = Cast<AMyCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
		if (!MyCharacter)
			return;

		FString hpString = FString::FromInt(MyCharacter->GetHP());
		DrawText(TEXT("HP: "+ hpString), FColor::Black, 0, 100, hudFont, 0.5f );

		int32 MonsterCount = 0;
		TArray<AActor*> FoundActors;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), AMonster::StaticClass(), FoundActors);
		for (auto Actor : FoundActors)
		{
			AMonster* MonsterActor = Cast<AMonster>(Actor);
			if (MonsterActor)
			{
				++MonsterCount;
			}
		}
		
		FString EnemyCountString = FString::FromInt(MonsterCount);
		DrawText(TEXT("Enemy: " + EnemyCountString), FColor::Black, 0, 200, hudFont, 0.5f);
	}break;
	case EPlayState::EPS_Clear:
	{
		DrawText(TEXT("GameClear"), FColor::Blue, 100, 0, hudFont);
	}break;
	case EPlayState::EPS_GameOver:
	{
		DrawText(TEXT("GameOver"), FColor::Red, 100, 0, hudFont);
	}break;
	default:
		break;
	}
}
