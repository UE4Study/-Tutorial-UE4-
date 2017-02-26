// Fill out your copyright notice in the Description page of Project Settings.

#include "GoldenEgg.h"
#include "Avater.h"


// Sets default values
AAvater::AAvater()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAvater::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAvater::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void AAvater::SetupPlayerInputComponent(UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
	InputComponent->BindAxis("Forward", this, &AAvater::MoveForward);
	InputComponent->BindAxis("Strafe", this, &AAvater::MoveRight);

	InputComponent->BindAxis("Yaw", this, &AAvater::Yaw);
	InputComponent->BindAxis("Pitch", this, &AAvater::Pitch);
}

void AAvater::MoveForward(float amount)
{
	if (Controller && amount)
	{
		FVector fwd = GetActorForwardVector();
		AddMovementInput(fwd, amount);
	}
}

void AAvater::MoveRight(float amount)
{
	if (Controller && amount)
	{
		FVector right = GetActorRightVector();
		AddMovementInput(right, amount);
	}
}

//void AAvater::MoveBack(float amount)
//{
//	if (Controller && amount)
//	{
//		FVector back = -GetActorForwardVector();
//		AddMovementInput(back, amount);
//	}
//}
//
//void AAvater::MoveLeft(float amount)
//{
//	if (Controller && amount)
//	{
//		FVector left = -GetActorRightVector();
//		AddMovementInput(left, amount);
//	}
//}

void AAvater::Yaw(float amount)
{
	AddControllerYawInput(200.0f * amount * GetWorld()->GetDeltaSeconds());
}

void AAvater::Pitch(float amount)
{
	AddControllerPitchInput(200.0f * amount * GetWorld()->GetDeltaSeconds());
}