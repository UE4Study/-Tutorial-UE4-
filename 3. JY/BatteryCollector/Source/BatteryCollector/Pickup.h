// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Pickup.generated.h"

UCLASS()
class BATTERYCOLLECTOR_API APickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickup();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	//픽업 메쉬 가져오기
	FORCEINLINE class UStaticMeshComponent* GetMesh() const { return PickupMesh; }

private:

	//설정
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "pickup", meta = (AllowPrivateAccess = "true"));
	
	//메쉬 전방선언
	class UStaticMeshComponent* PickupMesh;
	
};
