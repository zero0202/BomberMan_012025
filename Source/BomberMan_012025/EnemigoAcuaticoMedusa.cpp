// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemigoAcuaticoMedusa.h"
#include "BomberMan_012025GameMode.h"
#include "Engine/World.h"

AEnemigoAcuaticoMedusa::AEnemigoAcuaticoMedusa()
{
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
	if (MeshAsset.Succeeded())
	{
		MeshEnemigo->SetStaticMesh(MeshAsset.Object);
	}
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> ObjetoBloqueMaterial(TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/RosaMedusa.RosaMedusa'"));
	if (ObjetoBloqueMaterial.Succeeded())
	{
		MeshEnemigo->SetMaterial(0, ObjetoBloqueMaterial.Object);
	}

	AjustarTamano(FVector(3.0f, 3.0f, 1.5f));

	VelocidadMovimineto = 150.0f;
	Vida = 80;
	Danio = 15;

	TiempoTotal = 0.0f;
	FrecuenciaOndulacion = 5.0f;
	AmplitudOndulacion = 90.0f;

	// Dirección inicial aleatoria
	DireccionMovimiento = FVector(1, 0, 0);
}

void AEnemigoAcuaticoMedusa::BeginPlay()
{
	Super::BeginPlay();

	if (GameModeReference && GameModeReference->PuntosPatrullaLibres.Num() > 0)
	{
		int32 Index = FMath::RandRange(0, GameModeReference->PuntosPatrullaLibres.Num() - 1);
		SetActorLocation(GameModeReference->PuntosPatrullaLibres[Index]);

		int32 DireccionAleatoria = FMath::RandRange(0, 3);
		switch (DireccionAleatoria)
		{
		case 0: DireccionMovimiento = FVector(1, 0, 0); break;
		case 1: DireccionMovimiento = FVector(-1, 0, 0); break;
		case 2: DireccionMovimiento = FVector(0, 1, 0); break;
		case 3: DireccionMovimiento = FVector(0, -1, 0); break;
		}
	}
}

void AEnemigoAcuaticoMedusa::Tick(float DeltaTime)
{
	TiempoTotal += DeltaTime;

	FVector BaseDireccion = DireccionMovimiento * VelocidadMovimineto * DeltaTime;
	FVector MovimientoOndulante = BaseDireccion;

	// Agregamos una oscilación senoidal en el eje perpendicular
	if (DireccionMovimiento.X != 0)
	{
		MovimientoOndulante.Y = FMath::Sin(TiempoTotal * FrecuenciaOndulacion) * AmplitudOndulacion * DeltaTime;
	}
	else
	{
		MovimientoOndulante.X = FMath::Sin(TiempoTotal * FrecuenciaOndulacion) * AmplitudOndulacion * DeltaTime;
	}

	FVector NuevaPos = GetActorLocation() + MovimientoOndulante;

	if (GameModeReference && EsEspacioLibre(NuevaPos))
	{
		SetActorLocation(NuevaPos);
	}
	else
	{
		CambiarDireccion();
	}
}

void AEnemigoAcuaticoMedusa::CambiarDireccion()
{
	int32 NuevaDireccion = FMath::RandRange(0, 3);
	switch (NuevaDireccion)
	{
	case 0: DireccionMovimiento = FVector(1, 0, 0); break;
	case 1: DireccionMovimiento = FVector(-1, 0, 0); break;
	case 2: DireccionMovimiento = FVector(0, 1, 0); break;
	case 3: DireccionMovimiento = FVector(0, -1, 0); break;
	}
}

