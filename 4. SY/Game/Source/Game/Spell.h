// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Spell.generated.h"

UCLASS()
class GAME_API ASpell : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpell();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	void SetCaster(AActor* caster);

protected:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Spell)
		class UBoxComponent* ProxBox;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Spell)
		class UParticleSystemComponent* Particles;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Spell)
		float DeamagePerSecond;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Spell)
		float Duration;

	float TimeAlive;
	AActor* Caster;
};
