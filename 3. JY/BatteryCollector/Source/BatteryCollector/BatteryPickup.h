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

	//파워값 얻기
	float GetPower();
	
protected:

	//캐릭터로 보내는 배터리 파워
	//BlueprintProtected = "true" : 상속받은 블루프린트에서도 값을 변경할 수 있게 함
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Power", meta = (BlueprintProtected = "true"))
	float BatteryPower;

};
