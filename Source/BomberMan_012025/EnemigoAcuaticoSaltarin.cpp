// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemigoAcuaticoSaltarin.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "BomberMan_012025GameMode.h"

AEnemigoAcuaticoSaltarin::AEnemigoAcuaticoSaltarin()
{
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_TriPyramid.Shape_TriPyramid'"));
	if (MeshAsset.Succeeded())
	{
		MeshEnemigo->SetStaticMesh(MeshAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterialInterface> ObjetoBloqueMaterial(TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/M_Water_Ocean.M_Water_Ocean'"));
	if (ObjetoBloqueMaterial.Succeeded())
	{
		MeshEnemigo->SetMaterial(0, ObjetoBloqueMaterial.Object);
	}

	AjustarTamano(FVector(4.0f, 4.0f, 5.5f));

	VelocidadMovimineto = 100.f;
	bSaltando = false;
	TiempoEnAire = 0.0f;
	DuracionSalto = 1.0f;
}

void AEnemigoAcuaticoSaltarin::BeginPlay()
{
	Super::BeginPlay();
	if (GameModeReference && GameModeReference->PuntosPatrullaLibres.Num() > 0)
	{
		int32 Index = FMath::RandRange(0, GameModeReference->PuntosPatrullaLibres.Num() - 1);
		SetActorLocation(GameModeReference->PuntosPatrullaLibres[Index]);
		IniciarSalto();
	}
}

void AEnemigoAcuaticoSaltarin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!bSaltando) return;

	TiempoEnAire += DeltaTime;
	float Alpha = TiempoEnAire / DuracionSalto;

	if (Alpha >= 1.0f)
	{
		SetActorLocation(ObjetivoSalto);
		IniciarSalto();
		return;
	}

	FVector PosicionIntermedia = FMath::Lerp(PosicionInicial, ObjetivoSalto, Alpha);
	float Alturah = 300.f * FMath::Sin(Alpha * PI); // curva de salto
	PosicionIntermedia.Z += Alturah;
	SetActorLocation(PosicionIntermedia);
}

void AEnemigoAcuaticoSaltarin::IniciarSalto()
{
	PosicionInicial = GetActorLocation();
	ObjetivoSalto = CalcularNuevoDestino();
	TiempoEnAire = 0.0f;
	bSaltando = true;
}

FVector AEnemigoAcuaticoSaltarin::CalcularNuevoDestino()
{
	if (!GameModeReference) return GetActorLocation();

	TArray<FVector> OpcionesValidas;
	FVector PosActual = GetActorLocation();
	TArray<FVector> Direcciones = {
		FVector(Espaciado, 0, 0), FVector(-Espaciado, 0, 0),
		FVector(0, Espaciado, 0), FVector(0, -Espaciado, 0)
	};

	for (const FVector& Dir : Direcciones)
	{
		FVector NuevaPos = PosActual + Dir;
		if (EsEspacioLibre(NuevaPos))
		{
			OpcionesValidas.Add(NuevaPos);
		}
	}

	if (OpcionesValidas.Num() > 0)
	{
		return OpcionesValidas[FMath::RandRange(0, OpcionesValidas.Num() - 1)];
	}

	return PosActual;
}
