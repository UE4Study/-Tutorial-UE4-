// Fill out your copyright notice in the Description page of Project Settings.

#include "Game.h"
#include "MyCharacter.h"
#include "Bullet.h"


// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	BulletLaunchImpulse = 2000.0f;
	AttackTimeout = 1.5f;
	TimeSinceLastStrike = 0;
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyCharacter::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	AddMovementInput(knockback, 1.f);
	knockback *= 0.5f;

	//TimeSinceLastStrike += DeltaTime;

	//if (TimeSinceLastStrike > AttackTimeout)
	//{
	//	TimeSinceLastStrike = 0;
	//}

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("Forward", this, &AMyCharacter::MoveForward);
	PlayerInputComponent->BindAxis("Strafe", this, &AMyCharacter::MoveRight);
	PlayerInputComponent->BindAxis("Yaw", this, &AMyCharacter::Yaw);
	PlayerInputComponent->BindAxis("Pitch", this, &AMyCharacter::Pitch);
	
	PlayerInputComponent->BindAction("Shot", IE_Pressed, this, &AMyCharacter::Attack);
}

void AMyCharacter::MoveForward(float amount)
{
	if (Controller && amount)
	{
		FVector forward = GetActorForwardVector();
		AddMovementInput(forward, amount);
	}
}

void AMyCharacter::MoveRight(float amount)
{
	if (Controller && amount)
	{
		FVector right = GetActorRightVector();
		AddMovementInput(right, amount);
	}
}

void AMyCharacter::Yaw(float amount)
{
	AddControllerYawInput(200.0f * amount * GetWorld()->GetDeltaSeconds());
}

void AMyCharacter::Pitch(float amount)
{
	AddControllerPitchInput(200.0f * amount * GetWorld()->GetDeltaSeconds());
}

float AMyCharacter::TakeDamage(float Damage,FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	knockback = GetActorLocation() - DamageCauser->GetActorLocation();
	knockback.Normalize();
	knockback *= Damage * 500;

	return Damage;
}

void AMyCharacter::Attack()
{
	//if (TimeSinceLastStrike)
	//	return;

	if (BPBullet)
	{
		FVector forward = GetActorForwardVector();
		FVector nozzle = GetMesh()->GetBoneLocation("hand_l");
		nozzle += forward * 100;
		FVector toOpponent = GetActorLocation() - nozzle;
		toOpponent.Normalize();
		ABullet* bullet = GetWorld()->SpawnActor<ABullet>(BPBullet, nozzle, RootComponent->GetComponentRotation());
		if (bullet)
		{
			bullet->ProxSphere->AddImpulse(forward*BulletLaunchImpulse);
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(0, 5.f, FColor::Yellow, "character: no bullet actor could be spawned. is the bullet overlapping something?");
		}
	}
}
