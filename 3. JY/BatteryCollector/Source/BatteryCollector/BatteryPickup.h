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

	//�⺻�� ����
	ABatteryPickup();

	//�Ⱦ�Ŭ�������� �������̵�
	void WasCollected_Implementation() override;

	//�Ŀ��� ���
	float GetPower();
	
protected:

	//ĳ���ͷ� ������ ���͸� �Ŀ�
	//BlueprintProtected = "true" : ��ӹ��� �������Ʈ������ ���� ������ �� �ְ� ��
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Power", meta = (BlueprintProtected = "true"))
	float BatteryPower;

};
