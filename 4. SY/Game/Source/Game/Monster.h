// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "Monster.generated.h"

UCLASS()
class GAME_API AMonster : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMonster();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void Attack(AActor* thing);
	//private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MonsterProperties)
	float Speed;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MonsterProperties)
		float HitPoints;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MonsterProperties)
		int32 Experience;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MonsterProperties)
		float BaseAttackDamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MonsterProperties)
		float AttackTimeout;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = MonsterProperties)
		float TimeSinceLastStrike;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Collision)
		USphereComponent* SightSphere;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Collision)
		USphereComponent* AttackRangeSphere;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MonsterProperties)
		UClass* BPBullet;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MonsterProperties)
		float BulletLaunchImpulse;

};
