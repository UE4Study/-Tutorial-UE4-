// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameModeBase.h"
#include "GameGameModeBase.generated.h"

UENUM(BlueprintType)
enum class EPlayState
{
	EPS_Play,
	EPS_Clear,
	EPS_GameOver,
	EPS_Max,
};

/**
 * 
 */
UCLASS()
class GAME_API AGameGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	AGameGameModeBase();

	virtual void Tick(float DeltaTime) override;

	virtual void BeginPlay() override;
	
	UFUNCTION(BlueprintPure, Category = "Player")
	EPlayState GetCurrentState() const;
	
	void SetCurrentState(EPlayState ChangeState);

private:
	EPlayState CurrentState;

	void HandleState(EPlayState changeState);
};
