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
	//TSubclassOf : APickup이나 자손클래스만으로 한정하여 사용할 수 있다.
	TSubclassOf<class APickup> WhatToSpawn;

	FTimerHandle SpawnTimer;

	//스폰 최대, 최소 지연시간
	//에디터에 편집가능, 가비지컬렉션에 포함, 블루프린트에서 동적 변경가능
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	float SpawnDelayRangeLow;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	float SpawnDelayRangeHigh;

private:

	//아이템 생성위치를 생성할 박스 컴포넌트
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawning", meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* WhereToSpawn;
	
	//픽업할 물체 스폰
	void SpawnPickup();

	//스폰 지연시간
	float SpawnDelay;
};
