// Fill out your copyright notice in the Description page of Project Settings.


#include "Moneda.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInterface.h"
#include "BomberMan_012025GameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/Engine.h"

AMoneda::AMoneda()
{

	PrimaryActorTick.bCanEverTick = true;

	MeshMoneda = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshMoneda"));
	MeshMoneda->SetupAttachment(RootComponent);
	RootComponent = MeshMoneda;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> ObjetoMeshMoneda(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
	if (ObjetoMeshMoneda.Succeeded())
	{
		MeshMoneda->SetStaticMesh(ObjetoMeshMoneda.Object);
		MeshMoneda->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
		MeshMoneda->SetWorldScale3D(FVector(5.3f, 6.0f, 5.9f));
	}

	static ConstructorHelpers::FObjectFinder<UMaterialInterface> ObjetoMonedaMaterial(TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/Moneda.Moneda'"));
	if (ObjetoMonedaMaterial.Succeeded())
	{
		MeshMoneda->SetMaterial(0, ObjetoMonedaMaterial.Object);
	}
	
}

void AMoneda::BeginPlay()
{
	Super::BeginPlay();
	GameModeRef = Cast<ABomberMan_012025GameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	PosicionInicial = GetActorLocation();
}

void AMoneda::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Cálculo del ángulo
	float DeltaGrados = VelocidadRotacion * DeltaTime * (bRotandoPositivo ? -1.f : 1.f);
	AnguloActual += FMath::Abs(DeltaGrados);

	// Aplicar la rotación real al actor
	FRotator RotacionDelta = FRotator(EjeRotacion.Y * DeltaGrados, EjeRotacion.Z * DeltaGrados, EjeRotacion.X * DeltaGrados);
	AddActorLocalRotation(RotacionDelta);
	// Si completó una vuelta completa en esta dirección
	if (AnguloActual >= AnguloMaximoRotacion)
	{
		AnguloActual = 0.f;
		bRotandoPositivo = !bRotandoPositivo; // cambiar dirección
		CiclosCompletos++;

		if (CiclosCompletos >= 2) // completo ida y vuelta
		{
			SaltarAPosicionAleatoria();
			CiclosCompletos = 0;
		}
	}
}

void AMoneda::SaltarAPosicionAleatoria()
{
	if (!GameModeRef) return;

	if (!bVolverAPosicionInicial)
	{
		const TArray<FVector>& Posiciones = GameModeRef->PuntosPatrullaLibres;
		if (Posiciones.Num() == 0) return;

		FVector NuevaPosicion = Posiciones[FMath::RandRange(0, Posiciones.Num() - 1)];
		NuevaPosicion.Z = GetActorLocation().Z; // Mantener altura actual
		SetActorLocation(NuevaPosicion);
		UE_LOG(LogTemp, Warning, TEXT("Moneda saltó a nueva posición: %s"), *NuevaPosicion.ToString());

		bVolverAPosicionInicial = true;
	}
	else
	{
		FVector Regreso = PosicionInicial;
		Regreso.Z = GetActorLocation().Z; // Mantener altura visual
		SetActorLocation(Regreso);
		UE_LOG(LogTemp, Warning, TEXT("Moneda volvió a su posición inicial: %s"), *Regreso.ToString());

		bVolverAPosicionInicial = false;
	}
}

