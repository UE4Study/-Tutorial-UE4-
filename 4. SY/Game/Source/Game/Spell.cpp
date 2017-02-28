// Fill out your copyright notice in the Description page of Project Settings.

#include "Game.h"
#include "Spell.h"
#include "Monster.h"

// Sets default values
ASpell::ASpell()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ProxBox = CreateDefaultSubobject<UBoxComponent>(TEXT("ProxBox"));
	Particles = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleSystem"));

	RootComponent = Particles;
	ProxBox->SetupAttachment(RootComponent);
	Duration = 3;
	DeamagePerSecond = 1;
	TimeAlive = 0;
}

// Called when the game starts or when spawned
void ASpell::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpell::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	TArray<AActor*> actors;

	ProxBox->GetOverlappingActors(actors);
	for (int i = 0; i < actors.Num(); i++)
	{
		AMonster* monster = Cast<AMonster>(actors[i]);
		if (monster && ProxBox->IsOverlappingComponent(monster->GetCapsuleComponent()))
		{
			monster->TakeDamage(DeamagePerSecond*DeltaTime, FDamageEvent(), 0, this);
		}
	}

	TimeAlive += DeltaTime;
	if (TimeAlive > Duration)
	{
		Destroy();
	}
}

void ASpell::SetCaster(AActor* caster)
{
	Caster = caster;
	AttachRootComponentTo(caster->GetRootComponent());
}