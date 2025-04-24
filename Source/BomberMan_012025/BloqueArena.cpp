// Fill out your copyright notice in the Description page of Project Settings.

#include "BloqueArena.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInterface.h"
#include "Particles/ParticleSystemComponent.h"
#include "GameFramework/Character.h"
#include "Engine/Engine.h"

ABloqueArena::ABloqueArena()
{
	PrimaryActorTick.bCanEverTick = true;


	static ConstructorHelpers::FObjectFinder<UStaticMesh> ObjetoMeshBloqueArena(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	if (ObjetoMeshBloqueArena.Succeeded())
	{
		MeshBloque->SetStaticMesh(ObjetoMeshBloqueArena.Object);

		MeshBloque->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	}
	//para asignar textura
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> ObjetoBloqueAceroMaterial(TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/M_Metal_Gold.M_Metal_Gold'"));
	if (ObjetoBloqueAceroMaterial.Succeeded())
	{
		MeshBloque->SetMaterial(0, ObjetoBloqueAceroMaterial.Object);
	}
	//para simular polvo
	static ConstructorHelpers::FObjectFinder<UParticleSystem> ArenaFX(TEXT("/Game/StarterContent/Particles/P_Steam_Lit.P_Steam_Lit"));
	if (ArenaFX.Succeeded())
	{
		Particulas->SetTemplate(ArenaFX.Object);
	}

	// Configurar la colision
	MeshBloque->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	MeshBloque->OnComponentBeginOverlap.AddDynamic(this, &ABloqueArena::OnOverlapBegin);  // Detectar cuando empieza la colisión


	velocidadA = 5.0f;
	Amplitud = 100.0f;
	Direccion = 1.0f; // 1 = hacia arriba, -1 = hacia abajo

	PuedeMoverseA = true;
}

void ABloqueArena::BeginPlay()
{
	Super::BeginPlay();
	PosicionInicial = GetActorLocation();
}

void ABloqueArena::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    if (PuedeMoverseA)
	{ 
		FVector PosicionActual = GetActorLocation();

		// Mover hacia arriba o abajo según la dirección
		PosicionActual.Z += Direccion * velocidadA * DeltaTime;

		float DistanciaZ = PosicionActual.Z - PosicionInicial.Z;
		// Verificar si alcanzó el límite de movimiento
		if (DistanciaZ >= Amplitud || DistanciaZ <= -Amplitud)
		{
			Direccion *= -1.0f;
		}

		// Aplicar la nueva posición
		SetActorLocation(PosicionActual);
	}
}

void ABloqueArena::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Verificar si el actor que colisiona es el personaje
	ACharacter* Personaje = Cast<ACharacter>(OtherActor);
	if (Personaje)
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Orange, TEXT("Choco con el bloque arena"));

	}
}

