// Fill out your copyright notice in the Description page of Project Settings.


#include "BloqueConcreto.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInterface.h"
#include "Particles/ParticleSystemComponent.h"

ABloqueConcreto::ABloqueConcreto()
{
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshBloqueConcretoAsset(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	if (MeshBloqueConcretoAsset.Succeeded())
	{
		MeshBloque->SetStaticMesh(MeshBloqueConcretoAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterialInterface> BloqueConcretoMaterialAsset(TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/M_Metal_Copper.M_Metal_Copper'"));
	if (BloqueConcretoMaterialAsset.Succeeded())
	{
		MeshBloque->SetMaterial(0, BloqueConcretoMaterialAsset.Object);
	}

	ParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleSystem"));
	ParticleSystem->SetupAttachment(RootComponent);

	// Encontrar una partícula que simule vapor o niebla
	static ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleSystemAsset(TEXT("/Game/StarterContent/Particles/P_Steam_Lit.P_Steam_Lit"));
	if (ParticleSystemAsset.Succeeded())
	{
		ParticleSystem->SetTemplate(ParticleSystemAsset.Object);

		// Escalar el sistema de partículas para que sea más grande
		ParticleSystem->SetWorldScale3D(FVector(1.0f, 1.0f, 1.5f));
	}

}

void ABloqueConcreto::BeginPlay()
{
	Super::BeginPlay();

}

void ABloqueConcreto::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewLocation = GetActorLocation();

	// Movimiento en el eje X (lado a lado)
	float DeltaX = FMath::Sin(GetWorld()->GetTimeSeconds() * 2.0f) * 5.0f; // Oscilación en X

	// Movimiento en el eje Z (arriba y abajo)
	float DeltaZ = FMath::Sin(GetWorld()->GetTimeSeconds() * 3.0f) * 5.0f; // Oscilación en Z

	// Aplicar el movimiento
	NewLocation.X += DeltaX;
	NewLocation.Z = 50.0f + DeltaZ;  // Base elevada para que no se hunda en el suelo

	SetActorLocation(NewLocation);

}
