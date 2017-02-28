// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

UCLASS()
class GAME_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveForward(float amount);
	void MoveRight(float amount);

	void Yaw(float amount);
	void Pitch(float amount);

	float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser);
	void CastSpell();
	void CastSpell2();

	UFUNCTION(BlueprintPure, Category = Properties)
		int32 GetHP() const;
protected:
	FVector knockback;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Properties)
		UClass* BPSpell;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Properties)
		UClass* BPSpell2;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Properties)
		int32 HP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Properties)
		float SpellTimeout;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Properties)
		float TimeSinceLastSpell;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Properties)
		float SpellTimeout2;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Properties)
		float TimeSinceLastSpell2;

};
