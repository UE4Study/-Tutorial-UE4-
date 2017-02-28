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

	Speed = 30;
	AttackTimeout = 1.5f;
	TimeSinceLastStrike = 0;
	BulletLaunchImpulse = 2000.0f;
	HP = 100;

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

	AddMovementInput(knockback, 1.f);
	knockback *= 0.5f;

	AMyCharacter* MyCharacter = Cast<AMyCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	if (!MyCharacter)
		return;

	if (MyCharacter->GetHP() <= 0)
		return;

	FVector toPlayer = MyCharacter->GetActorLocation() - GetActorLocation();
	float distanceToPlayer = toPlayer.Size();
	if (distanceToPlayer > SightSphere->GetScaledSphereRadius())
		return;
	
	toPlayer /= distanceToPlayer;
	
	FRotator toPlayerRotation = toPlayer.Rotation();
	toPlayerRotation.Pitch = 0;
	RootComponent->SetWorldRotation(toPlayerRotation);

	if (AttackRangeSphere->GetScaledSphereRadius() < distanceToPlayer)
	{
		AddMovementInput(toPlayer, Speed*DeltaTime);
	}
	
	if (!TimeSinceLastStrike)
	{
		Attack(MyCharacter);
	}
	TimeSinceLastStrike += DeltaTime;

	if (TimeSinceLastStrike > AttackTimeout)
	{
		TimeSinceLastStrike = 0;
	}

}

// Called to bind functionality to input
void AMonster::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

float AMonster::TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	HP -= Damage;
	if (HP <= 0)
	{
		Destroy();
	}

	knockback = GetActorLocation() - DamageCauser->GetActorLocation();
	knockback.Normalize();
	knockback *= Damage * 500;

	return Damage;
}

void AMonster::Attack(AActor* thing)
{
	if (!BPBullet)
		return;
	
	FVector forward = GetActorForwardVector();
	FVector nozzle = GetMesh()->GetBoneLocation("hand_l");
	nozzle += forward * 100;
	ABullet* bullet = GetWorld()->SpawnActor<ABullet>(BPBullet, nozzle, RootComponent->GetComponentRotation());
	if (bullet)
	{
		FVector toThing = thing->GetActorLocation() - GetActorLocation();
		toThing.Normalize();
		bullet->ProxSphere->AddImpulse(toThing*BulletLaunchImpulse);
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(0, 5.f, FColor::Yellow, "monster: no bullet actor could be spawned. is the bullet overlapping something?");
	}
}

int32 AMonster::GetHP() const
{
	return HP;
}

