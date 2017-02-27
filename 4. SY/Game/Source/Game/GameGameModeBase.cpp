// Fill out your copyright notice in the Description page of Project Settings.

#include "Game.h"
#include "GameGameModeBase.h"

AGameGameModeBase::AGameGameModeBase()
{
	//static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT(/))
	PrimaryActorTick.bCanEverTick = true;
}

void AGameGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	SetCurrentState(EPlayState::EPS_Play);
}


void AGameGameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

EPlayState AGameGameModeBase::GetCurrentState() const
{
	return CurrentState;
}

void AGameGameModeBase::SetCurrentState(EPlayState ChangeState)
{
	CurrentState = ChangeState;
}