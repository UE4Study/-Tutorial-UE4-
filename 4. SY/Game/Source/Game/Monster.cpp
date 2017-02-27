// Fill out your copyright notice in the Description page of Project Settings.

#include "Game.h"
#include "Monster.h"
#include "MyCharacter.h"
#include "Bullet.h"

// Sets default values
AMonster::AMonster()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Speed = 20;
	HitPoints = 20;
	Experience = 0;
	BaseAttackDamage = 1;
	AttackTimeout = 1.5f;
	TimeSinceLastStrike = 0;
	BulletLaunchImpulse = 2000.0f;
	SightSphere = CreateDefaultSubobject<USphereComponent>(TEXT("SightSphere"));
	SightSphere->SetupAttachment(RootComponent);

	AttackRangeSphere = CreateDefaultSubobject<USphereComponent>(TEXT("AttackRangeSphere"));
	AttackRangeSphere->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AMonster::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMonster::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	AMyCharacter* MyCharacter = Cast<AMyCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	if (!MyCharacter)
		return;

	FVector toPlayer = MyCharacter->GetActorLocation() - GetActorLocation();
	//toPlayer.Normalize();
	float distanceToPlayer = toPlayer.Size();
	if (distanceToPlayer > SightSphere->GetScaledSphereRadius())
		return;
	
	toPlayer /= distanceToPlayer;
	AddMovementInput(toPlayer, Speed*DeltaTime);
	
	FRotator toPlayerRotation = toPlayer.Rotation();
	toPlayerRotation.Pitch = 0;
	RootComponent->SetWorldRotation(toPlayerRotation);

	if (AttackRangeSphere->GetScaledSphereRadius() < distanceToPlayer)
	{
		if (!TimeSinceLastStrike)
		{
			Attack(MyCharacter);
		}
		TimeSinceLastStrike += DeltaTime;
	
		if (TimeSinceLastStrike > AttackTimeout)
		{
			TimeSinceLastStrike = 0;
		}
		return;
	}
	else
	{
		AddMovementInput(toPlayer, Speed*DeltaTime);
	}
}

// Called to bind functionality to input
void AMonster::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AMonster::Attack(AActor* thing)
{
	if (BPBullet)
	{
		FVector forward = GetActorForwardVector();
		FVector nozzle = GetMesh()->GetBoneLocation("hand_l");
		nozzle += forward * 155;
		FVector toOpponent = thing->GetActorLocation() - nozzle;
		toOpponent.Normalize();
		ABullet* bullet = GetWorld()->SpawnActor<ABullet>(BPBullet, nozzle, RootComponent->GetComponentRotation());
		if (bullet)
		{
			//bullet->Firer = this;
			bullet->ProxSphere->AddImpulse(forward*BulletLaunchImpulse);
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(0, 5.f, FColor::Yellow, "monster: no bullet actor could be spawned. is the bullet overlapping something?");
		}
	}
}

