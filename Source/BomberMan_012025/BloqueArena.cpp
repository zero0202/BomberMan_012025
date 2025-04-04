// Fill out your copyright notice in the Description page of Project Settings.


#include "BloqueArena.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInterface.h"
#include "Particles/ParticleSystemComponent.h"
#include "Particles/ParticleSystem.h"

ABloqueArena::ABloqueArena()
{
	PrimaryActorTick.bCanEverTick = true;


	static ConstructorHelpers::FObjectFinder<UStaticMesh> ObjetoMeshBloqueAcero(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	if (ObjetoMeshBloqueAcero.Succeeded())
	{
		MeshBloque->SetStaticMesh(ObjetoMeshBloqueAcero.Object);

		MeshBloque->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	}
	//para asignar textura
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> ObjetoBloqueAceroMaterial(TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/M_Metal_Gold.M_Metal_Gold'"));
	if (ObjetoBloqueAceroMaterial.Succeeded())
	{
		MeshBloque->SetMaterial(0, ObjetoBloqueAceroMaterial.Object);

	}

	// Partículas de polvo/sand
	ParticulasArena = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticulasArena"));
	ParticulasArena->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UParticleSystem> ArenaFX(TEXT("/Game/StarterContent/Particles/P_Steam_Lit.P_Steam_Lit")); // usa este como polvo temporal
	if (ArenaFX.Succeeded())
	{
		ParticulasArena->SetTemplate(ArenaFX.Object);
	}

	TiempoArena = 0.f;
}

void ABloqueArena::BeginPlay()
{
	Super::BeginPlay();
	PosicionInicial = GetActorLocation();
	ParticulasArena->Activate();
}

void ABloqueArena::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TiempoArena += DeltaTime;

	// Movimiento suave y constante tipo onda senoidal (como si "respirara arena")
	float Amplitud = 5.0f;          // Qué tanto sube/baja
	float Frecuencia = 3.5f;        // Qué tan rápido sube/baja

	float DesplazamientoZ = FMath::Sin(TiempoArena * Frecuencia) * Amplitud;

	FVector NuevaPos = PosicionInicial;
	NuevaPos.Z = PosicionInicial.Z + DesplazamientoZ;

	SetActorLocation(NuevaPos);

}
