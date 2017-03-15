// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/GameInstance.h"
#include "WebConnection.h"
#include "ABGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class ARENABATTLE_API UABGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UABGameInstance();
	virtual void Init() override;
	
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "WebService")
	class UWebConnection* WebConnection;

	UPROPERTY()
	class UWebConnection* WebConnectionNew;
	
	UPROPERTY()
	FStreamableManager AssetLoader;

	UFUNCTION()
	void RequestTokenComplete(const FString& Token);
};
