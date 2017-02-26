// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "Avater.generated.h"

UCLASS()
class GOLDENEGG_API AAvater : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAvater();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	void MoveForward(float amount);
	void MoveRight(float amount);
	//void MoveLeft(float amount);
	//void MoveBack(float amount);

	void Yaw(float amount);
	void Pitch(float amount);
};
