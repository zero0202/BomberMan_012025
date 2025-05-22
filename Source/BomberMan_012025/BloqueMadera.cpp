// Fill out your copyright notice in the Description page of Project Settings.


#include "BloqueMadera.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInterface.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "Particles/ParticleSystemComponent.h"

ABloqueMadera::ABloqueMadera() 
{
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> ObjetoMeshBloqueMadera(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	if (ObjetoMeshBloqueMadera.Succeeded())
	{
		MeshBloque->SetStaticMesh(ObjetoMeshBloqueMadera.Object);
		MeshBloque->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	}
	//para asignar textura al bloque
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> ObjetoBloqueMaderaMaterial(TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/M_Wood_Oak.M_Wood_Oak'"));
	if (ObjetoBloqueMaderaMaterial.Succeeded())
	{
		MeshBloque->SetMaterial(0, ObjetoBloqueMaderaMaterial.Object);
	}

	// Inicializar variables
	MoverBloque = false;
	bAbriendo = false;
	VelocidadMovimiento = 100.0f; // Velocidad de movimiento
	DistanciaApertura = 200.0f;   // Distancia máxima de apertura
	PosicionInicial = FVector::ZeroVector; // Se inicializará en BeginPlay


	bDestruible = true;

}

void ABloqueMadera::BeginPlay()
{
	Super::BeginPlay();
	PosicionInicial = GetActorLocation(); // Guardar la posición inicial
}

void ABloqueMadera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	TiempoMovimiento += DeltaTime;
	if (MoverBloque) {
		// Obtener la posición actual del bloque
		FVector NuevaPosicion = GetActorLocation();

		// Mover hacia la derecha (abrir) o hacia la izquierda (cerrar) según el estado
		if (bAbriendo)
		{
			// Mover hacia la derecha (abrir)
			NuevaPosicion.X += VelocidadMovimiento * DeltaTime;
			if (NuevaPosicion.X >= PosicionInicial.X + DistanciaApertura)
			{
				bAbriendo = false; // Cambiar dirección a cerrar
			}
		}
		else
		{
			// Mover hacia la izquierda (cerrar)
			NuevaPosicion.X -= VelocidadMovimiento * DeltaTime;
			if (NuevaPosicion.X <= PosicionInicial.X)
			{
				bAbriendo = true; // Cambiar dirección a abrir
			}
		}

		// Aplicar la nueva posición
		SetActorLocation(NuevaPosicion);
	}
}

AActor* ABloqueMadera::Clonar(UWorld* Mundo, const FVector& Posicion) const
{
	if (!Mundo) return nullptr;

	FActorSpawnParameters SpawnParams;
	ABloqueMadera* Nuevo = Mundo->SpawnActor<ABloqueMadera>(GetClass(), Posicion, GetActorRotation(), SpawnParams);

	// Copiar estado relevante
	if (Nuevo)
	{
		Nuevo->TiempoMovimiento = this->TiempoMovimiento;
		// puedes copiar más propiedades si necesitas
	}

	return Nuevo;
}


