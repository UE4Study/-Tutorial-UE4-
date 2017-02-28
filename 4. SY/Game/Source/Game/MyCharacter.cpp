// Fill out your copyright notice in the Description page of Project Settings.

#include "Game.h"
#include "MyCharacter.h"
#include "Bullet.h"
#include "Spell.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SpellTimeout = 3.5f;
	SpellTimeout2 = 2.5f;
	TimeSinceLastSpell = 3.5f;
	TimeSinceLastSpell2 = 2.5f;
	HP = 100;
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

	TimeSinceLastSpell += DeltaTime;
	TimeSinceLastSpell2 += DeltaTime;

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("Forward", this, &AMyCharacter::MoveForward);
	PlayerInputComponent->BindAxis("Strafe", this, &AMyCharacter::MoveRight);
	PlayerInputComponent->BindAxis("Yaw", this, &AMyCharacter::Yaw);
	PlayerInputComponent->BindAxis("Pitch", this, &AMyCharacter::Pitch);
	
	PlayerInputComponent->BindAction("Spell", IE_Pressed, this, &AMyCharacter::CastSpell);
	PlayerInputComponent->BindAction("Spell2", IE_Pressed, this, &AMyCharacter::CastSpell2);
}

void AMyCharacter::MoveForward(float amount)
{
	if (Controller && amount)
	{
		FVector fwd = GetActorForwardVector();
		AddMovementInput(fwd, amount);
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
	HP -= Damage;
	knockback = GetActorLocation() - DamageCauser->GetActorLocation();
	knockback.Normalize();
	knockback *= Damage * 500;

	return Damage;
}

void AMyCharacter::CastSpell()
{
	if (TimeSinceLastSpell < SpellTimeout)
		return;
		
	TimeSinceLastSpell = 0;
	ASpell* spell = GetWorld()->SpawnActor<ASpell>(BPSpell, FVector(0), FRotator(0));
	if (spell)
	{
		spell->SetCaster(this);
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(1, 5.f, FColor::Yellow, FString(TEXT("변환 불가능")) + BPSpell->GetName());
	}
}

void AMyCharacter::CastSpell2()
{
	if (TimeSinceLastSpell2 < SpellTimeout2)
		return;

	TimeSinceLastSpell2 = 0;
	ASpell* spell2 = GetWorld()->SpawnActor<ASpell>(BPSpell2, FVector(0), FRotator(0));
	if (spell2)
	{
		spell2->SetCaster(this);
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(1, 5.f, FColor::Yellow, FString(TEXT("변환 불가능")) + BPSpell2->GetName());
	}
}

int32 AMyCharacter::GetHP() const
{
	return HP;
}