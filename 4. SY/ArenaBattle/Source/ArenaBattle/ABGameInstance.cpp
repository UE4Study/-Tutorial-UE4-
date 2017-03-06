// Fill out your copyright notice in the Description page of Project Settings.

#include "ArenaBattle.h"
#include "ABGameInstance.h"

UABGameInstance::UABGameInstance()
{
	UE_LOG(LogClass, Warning, TEXT("%s"), TEXT("GameInstance Constructor Start!"));
	WebConnection = CreateDefaultSubobject<UWebConnection>(TEXT("MyWebConnection"));
	UE_LOG(LogClass, Warning, TEXT("%s"), TEXT("GameInstance Constructor End!"));
}

void UABGameInstance::Init()
{
	Super::Init();

	UE_LOG(LogClass, Warning, TEXT("%s"), TEXT("game Instance Init!"));
}


