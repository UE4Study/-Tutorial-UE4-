// Fill out your copyright notice in the Description page of Project Settings.

#include "BatteryCollector.h"
#include "BatteryPickup.h"


ABatteryPickup::ABatteryPickup()
{
	//���͸��� �������� ������ ����ǵ��� �Ѵ�.
	GetMesh()->SetSimulatePhysics(true);
}

void ABatteryPickup::WasCollected_Implementation()
{
	Super::WasCollected_Implementation();

	//������ ���͸��� �ı��Ѵ�.
	Destroy();
}