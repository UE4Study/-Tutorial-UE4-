// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Bullet.generated.h"

UCLASS()
class GAME_API ABullet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABullet();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Properties)
		float Demage;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Collision)
		class UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Collision)
		class USphereComponent* ProxSphere;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Properties)
		class UParticleSystemComponent* Particles;

	UFUNCTION(BlueprintNativeEvent, Category = Collision)
		void OnProxOverlapBegin(UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult &SweepResult);
	virtual void OnProxOverlapBegin_Implementation(UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult &SweepResult);
};
