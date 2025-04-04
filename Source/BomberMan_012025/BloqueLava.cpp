// Fill out your copyright notice in the Description page of Project Settings.


#include "BloqueLava.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInterface.h"
#include "Particles/ParticleSystemComponent.h"

ABloqueLava::ABloqueLava()
{
	PrimaryActorTick.bCanEverTick = true;


	static ConstructorHelpers::FObjectFinder<UStaticMesh> ObjetoMeshBloqueAcero(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	if (ObjetoMeshBloqueAcero.Succeeded())
	{
		MeshBloque->SetStaticMesh(ObjetoMeshBloqueAcero.Object);

		MeshBloque->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	}
	//para asignar textura
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> ObjetoBloqueAceroMaterial(TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/Fuego.Fuego'"));
	if (ObjetoBloqueAceroMaterial.Succeeded())
	{
		MeshBloque->SetMaterial(0, ObjetoBloqueAceroMaterial.Object);

	}
	/*
	ParticleSystemL = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleSystemL"));
	ParticleSystemL->SetupAttachment(MeshBloque);

	// Cargar una partícula que simule lava o material derretido
	static ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleSystemAssetL(TEXT("/Script/Engine.ParticleSystem'/Game/StarterContent/Particles/P_Fire.P_Fire'"));
	if (ParticleSystemAssetL.Succeeded())
	{
		ParticleSystemL->SetTemplate(ParticleSystemAssetL.Object);
		ParticleSystemL->SetWorldScale3D(FVector(2.2f, 2.2f, 2.2f));  // Ajustar tamaño
	}
	*/
	ParticulasLava = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticulasLava"));
	ParticulasLava->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UParticleSystem> LavaFX(TEXT("/Game/StarterContent/Particles/P_Fire.P_Fire"));
	if (LavaFX.Succeeded())
	{
		ParticulasLava->SetTemplate(LavaFX.Object);
	}

	TiempoLava = 0.f;
}

void ABloqueLava::BeginPlay()
{
	Super::BeginPlay();
	ParticulasLava->Activate();
	PosicionInicial = GetActorLocation();
}
void ABloqueLava::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TiempoLava += DeltaTime;

	float DesplazamientoZ = FMath::Sin(TiempoLava * 2.0f) * 10.0f; // Subida y bajada suave
	FVector NuevaPosicion = PosicionInicial;
	NuevaPosicion.Z += DesplazamientoZ;

	SetActorLocation(NuevaPosicion);
}