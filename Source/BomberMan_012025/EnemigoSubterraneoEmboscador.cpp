// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemigoSubterraneoEmboscador.h"
#include "Components/SphereComponent.h"
#include "BomberMan_012025Character.h"
#include "BomberMan_012025GameMode.h"
#include "Engine/Engine.h"

AEnemigoSubterraneoEmboscador::AEnemigoSubterraneoEmboscador()
{
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Tube.Shape_Tube'"));
	if (MeshAsset.Succeeded())
	{
		MeshEnemigo->SetStaticMesh(MeshAsset.Object);
	}
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> ObjetoBloqueMaterial(TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/Emboscado.Emboscado'"));
	if (ObjetoBloqueMaterial.Succeeded())
	{
		MeshEnemigo->SetMaterial(0, ObjetoBloqueMaterial.Object);
	}



	AjustarTamano(FVector(6.0f, 6.0f, 5.5f));

	IndiceActual = 0;
	VelocidadPatrulla = 600.f;
	AlturaVueloPa = 100;

}

void AEnemigoSubterraneoEmboscador::BeginPlay()
{
	Super::BeginPlay();

	// Establecer la posición inicial del enemigo
	FVector PosicionInicialEnemigo = FVector(3440.0f, 4370.0f, 100.0f);  // Cambia estas coordenadas según lo que necesites
	SetActorLocation(PosicionInicialEnemigo);
	// Si los puntos de patrullaje están vacíos, añadir el punto inicial
	if (PuntosPatrulla.Num() == 0)
	{
		PuntosPatrulla.Add(GetActorLocation()); // Empieza desde la posición inicial
	}
}

void AEnemigoSubterraneoEmboscador::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector Direccion = GetActorForwardVector();
	FVector NuevaPos = GetActorLocation() + Direccion * VelocidadPatrulla * DeltaTime;

	if (EsEspacioLibre(NuevaPos))
	{
		SetActorLocation(NuevaPos);
	}
	else
	{
		CambiarDireccion();
	}
}



void AEnemigoSubterraneoEmboscador::CambiarDireccion()
{
	float Angulo = FMath::RandRange(0, 3) * 90.0f; // 0, 90, 180, 270
	SetActorRotation(FRotator(0, Angulo, 0));
}

void AEnemigoSubterraneoEmboscador::volarP(float DeltaTime)
{
	// Mueve suavemente el actor a la AlturaVuelo definida
	FVector PosicionActual = GetActorLocation();
	PosicionActual.Z = AlturaVueloPa;

	FVector NuevaPosicion = FMath::VInterpTo(GetActorLocation(), PosicionActual, DeltaTime, 2.0f);
	SetActorLocation(NuevaPosicion);
}
