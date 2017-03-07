// Fill out your copyright notice in the Description page of Project Settings.

#include "Game.h"
#include "GameGameModeBase.h"
#include "MyCharacter.h"
#include "Blueprint/UserWidget.h"
#include "Monster.h"

AGameGameModeBase::AGameGameModeBase()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AGameGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	ChangeMenuWidget(StartingWidgetClass);

	SetCurrentState(EPlayState::EPS_Play);
}

void AGameGameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

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

	if (MonsterCount <= 0)
		SetCurrentState(EPlayState::EPS_Clear);


	AMyCharacter* MyCharacter = Cast<AMyCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	if (!MyCharacter)
		return;

	if (MyCharacter->GetHP() > 0)
		return;

	SetCurrentState(EPlayState::EPS_GameOver);
}

EPlayState AGameGameModeBase::GetCurrentState() const
{
	return CurrentState;
}

void AGameGameModeBase::SetCurrentState(EPlayState ChangeState)
{
	CurrentState = ChangeState;
	
	HandleState(ChangeState);
}

void AGameGameModeBase::HandleState(EPlayState changeState)
{
	if (changeState != EPlayState::EPS_GameOver)
		return;
	
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);
	if (PlayerController)
	{
		PlayerController->SetCinematicMode(true, false, false, true, true);
	}
	ACharacter* MyCharacter = UGameplayStatics::GetPlayerCharacter(this, 0);
	if (MyCharacter)
	{
		MyCharacter->GetMesh()->SetSimulatePhysics(true);
		MyCharacter->GetMovementComponent()->MovementState.bCanJump = false;
	}
}

void AGameGameModeBase::ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass)
{
	if (CurrentWidget != nullptr)
	{
		CurrentWidget->RemoveFromViewport();
		CurrentWidget = nullptr;
	}

	if (NewWidgetClass != nullptr)
	{
		CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), NewWidgetClass);
		if (CurrentWidget != nullptr)
		{
			CurrentWidget->AddToViewport();
		}
	}
}