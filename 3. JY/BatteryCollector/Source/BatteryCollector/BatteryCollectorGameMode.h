// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/GameModeBase.h"
#include "BatteryCollectorGameMode.generated.h"

//���� �÷��� ���µ�
UENUM(BlueprintType)
enum class EBatteryPlayState
{
	EPlaying,
	EGameOver,
	EWon,
	EUnknown
};

UCLASS(minimalapi)
class ABatteryCollectorGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ABatteryCollectorGameMode();

	virtual void Tick(float DeltaTime) override;

	//���� �¸��� ���� �Ŀ��� ����
	UFUNCTION(BlueprintPure, Category = "Power")
	float GetPowerToWin() const;

	virtual void BeginPlay() override;

	//���� �÷��̻��� get set
	UFUNCTION(BlueprintPure, Category = "Power")
	EBatteryPlayState GetCurrentState() const;

	void SetCurrentState(EBatteryPlayState NewState);

protected:

	//ĳ���Ͱ� �Ҵ� �Ŀ��� ����
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Power", Meta = (BlueprintProtected = "true"))
	float DecayRate;

	//���� �¸��� ���� �Ŀ�
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Power", Meta = (BlueprintProtected = "true"))
	float PowerToWin;

	//HUD
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Power", Meta = (BlueprintProtected = "true"))
	TSubclassOf<class UUserWidget> HUDWidgetClass;
	
	//HUD
	class UUserWidget* CurrentWidget;

private:

	//���� �÷��� ����
	EBatteryPlayState CurrentState;
};



