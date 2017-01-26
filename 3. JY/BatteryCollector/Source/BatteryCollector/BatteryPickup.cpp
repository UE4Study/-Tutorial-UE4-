// Fill out your copyright notice in the Description page of Project Settings.

#include "BatteryCollector.h"
#include "BatteryPickup.h"


ABatteryPickup::ABatteryPickup()
{
	//배터리에 자유낙하 물리가 적용되도록 한다.
	GetMesh()->SetSimulatePhysics(true);

	BatteryPower = 150.0f;
}

void ABatteryPickup::WasCollected_Implementation()
{
	Super::WasCollected_Implementation();

	//습득한 배터리를 파괴한다.
	Destroy();
}

float ABatteryPickup::GetPower()
{
	return BatteryPower;
}