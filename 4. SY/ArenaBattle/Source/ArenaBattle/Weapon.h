// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Weapon.generated.h"

UCLASS()
class ARENABATTLE_API AWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeapon();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	class USkeletalMeshComponent* Weapon;
	
	UFUNCTION(BlueprintCallable, Category = "Weapon|Stat")
	float GetDamage() { return BaseDamage; }

private:
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Stat", meta = (AllowPrivateAccess = "true"))
	float BaseDamage;
};
