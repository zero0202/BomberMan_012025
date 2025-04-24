// Fill out your copyright notice in the Description page of Project Settings.


#include "BloqueHielo.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInterface.h"


ABloqueHielo::ABloqueHielo()
{
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ObjetoMeshBloqueAcero(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	if (ObjetoMeshBloqueAcero.Succeeded())
	{
		MeshBloque->SetStaticMesh(ObjetoMeshBloqueAcero.Object);
		MeshBloque->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	}
	//para asignar textura
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> ObjetoBloqueAceroMaterial(TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/M_Rock_Slate.M_Rock_Slate'"));
	if (ObjetoBloqueAceroMaterial.Succeeded())
	{
		MeshBloque->SetMaterial(0, ObjetoBloqueAceroMaterial.Object);
	}

	// Guardar posición inicial
	PosicionInicial = FVector::ZeroVector;
	TiempoMovimiento = 0.f;
}
void ABloqueHielo::BeginPlay()
{
	Super::BeginPlay();
	PosicionInicial = GetActorLocation();
}
void ABloqueHielo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	TiempoMovimiento += DeltaTime;

	
	float Amplitud = 20.0f;          // Altura de la onda
	float Frecuencia = 1.5f;         // Velocidad del movimiento

	float DesplazamientoZ = FMath::Sin(TiempoMovimiento * Frecuencia) * Amplitud;

	FVector NuevaPos = PosicionInicial;
	NuevaPos.Z += DesplazamientoZ;

	SetActorLocation(NuevaPos);
}