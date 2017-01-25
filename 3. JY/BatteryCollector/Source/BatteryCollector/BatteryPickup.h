// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Pickup.h"
#include "BatteryPickup.generated.h"

/**
 * 
 */
UCLASS()
class BATTERYCOLLECTOR_API ABatteryPickup : public APickup
{
	GENERATED_BODY()
	
public:

	//기본값 설정
	ABatteryPickup();

	//픽업클래스에서 오버라이딩
	void WasCollected_Implementation() override;
	
	
};
