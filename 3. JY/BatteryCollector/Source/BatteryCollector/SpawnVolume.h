// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "SpawnVolume.generated.h"

UCLASS()
class BATTERYCOLLECTOR_API ASpawnVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnVolume();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	FORCEINLINE class UBoxComponent* GetWhereToSpawn() const { return WhereToSpawn; }

	UFUNCTION(BlueprintPure, Category = "Spawning")
	FVector GetRandomPointInVolume();

protected:

	UPROPERTY(EditAnywhere, Category = "Spawning")
	//TSubclassOf : APickup�̳� �ڼ�Ŭ���������� �����Ͽ� ����� �� �ִ�.
	TSubclassOf<class APickup> WhatToSpawn;

	FTimerHandle SpawnTimer;

	//���� �ִ�, �ּ� �����ð�
	//�����Ϳ� ��������, �������÷��ǿ� ����, �������Ʈ���� ���� ���氡��
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	float SpawnDelayRangeLow;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	float SpawnDelayRangeHigh;

private:

	//������ ������ġ�� ������ �ڽ� ������Ʈ
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawning", meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* WhereToSpawn;
	
	//�Ⱦ��� ��ü ����
	void SpawnPickup();

	//���� �����ð�
	float SpawnDelay;
};
