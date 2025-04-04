// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemigoAereo.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Materials/MaterialInterface.h"
#include "Particles/ParticleSystemComponent.h"

AEnemigoAereo::AEnemigoAereo()
{
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Cylinder.Shape_Cylinder'"));
	if (MeshAsset.Succeeded())
	{
		MeshEnemigo->SetStaticMesh(MeshAsset.Object);
	}

	ParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleSystem"));
	ParticleSystem->SetupAttachment(RootComponent);


	AjustarTamanoA(FVector(3.0f,3.0f, 1.5f));
	GetCharacterMovement()->GravityScale = 0.0f;
}

void AEnemigoAereo::BeginPlay()
{
	Super::BeginPlay();

}

void AEnemigoAereo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Volar(DeltaTime);
}

void AEnemigoAereo::AjustarTamanoA(FVector NuevoTamano)
{
	MeshEnemigo->SetWorldScale3D(NuevoTamano);
}

void AEnemigoAereo::Volar(float DeltaTime)
{
	// Mueve suavemente el actor a la AlturaVuelo definida
	FVector PosicionActual = GetActorLocation();
	PosicionActual.Z = AlturaVuelo;

	FVector NuevaPosicion = FMath::VInterpTo(GetActorLocation(), PosicionActual, DeltaTime, 1.0f);
	SetActorLocation(NuevaPosicion);
}
