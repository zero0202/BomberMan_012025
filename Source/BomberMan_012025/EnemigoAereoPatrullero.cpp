// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemigoAereoPatrullero.h"
#include "Particles/ParticleSystemComponent.h"
#include "Components/StaticMeshComponent.h"

AEnemigoAereoPatrullero::AEnemigoAereoPatrullero()
{
	PrimaryActorTick.bCanEverTick = true;

    static ConstructorHelpers::FObjectFinder<UMaterialInterface> ObjetoBloqueMaterial(TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/EfectoF.EfectoF'"));
    if (ObjetoBloqueMaterial.Succeeded())
    {
        MeshEnemigo->SetMaterial(0, ObjetoBloqueMaterial.Object);

    }

    // Encontrar una partícula que simule vapor o niebla
    static ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleSystemAsset(TEXT("/Script/Engine.Material'/Game/StarterContent/Particles/Materials/M_Burst.M_Burst'"));
    if (ParticleSystemAsset.Succeeded())
    {
        ParticleSystem->SetTemplate(ParticleSystemAsset.Object);

        // Escalar el sistema de partículas para que sea más grande
        ParticleSystem->SetWorldScale3D(FVector(2.0f, 3.0f, 3.5f));
    }
 

	IndiceActual = 0;
	VelocidadPatrulla = 600.f;
}

void AEnemigoAereoPatrullero::BeginPlay()
{
	Super::BeginPlay();
    // Si los puntos A y B no están seteados, se los calcula automáticamente
    if (PuntosPatrulla.Num() == 0)
    {
        PuntosPatrulla.Add(GetActorLocation()); // Empieza desde la posición inicial
    }
}

void AEnemigoAereoPatrullero::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime); // mantiene altura

    if (PuntosPatrulla.Num() == 0) return;

    // Obtener el siguiente punto al que se mueve el enemigo
    FVector Destino = PuntosPatrulla[IndiceActual];
    FVector Direccion = (Destino - GetActorLocation()).GetSafeNormal();
    FVector Movimiento = Direccion * VelocidadPatrulla * DeltaTime;

    // Realizar un raycast para verificar que el camino esté libre
    FHitResult HitResult;
    FVector LineaFinal = GetActorLocation() + Movimiento;

    // Realiza el raycast desde la posición actual hasta el destino
    bool bHayObstaculo = GetWorld()->LineTraceSingleByChannel(HitResult, GetActorLocation(), LineaFinal, ECC_Visibility);

    if (!bHayObstaculo) // Si no hay obstáculos, mueve el enemigo
    {
        SetActorLocation(GetActorLocation() + Movimiento);
    }
    else
    {
        // Si hay un obstáculo, el enemigo debe cambiar de dirección
        CambiarDireccion();
    }

    // Si el enemigo llega al destino, cambiar al siguiente punto
    if (FVector::Dist(GetActorLocation(), Destino) < 100.f)
    {
        IndiceActual = (IndiceActual + 1) % PuntosPatrulla.Num(); // ciclo infinito
    }
}

void AEnemigoAereoPatrullero::CambiarDireccion()
{
    // Buscar un nuevo punto cercano disponible
    TArray<FVector> PosiblesDirecciones;

    for (FVector PuntoLibre : PuntosPatrulla)
    {
        // Aseguramos que el punto no esté ocupado (es un espacio libre 0)
        if (FVector::Dist(GetActorLocation(), PuntoLibre) > 5.0f) // Excluimos puntos muy cercanos
        {
            PosiblesDirecciones.Add(PuntoLibre);
        }
    }

    if (PosiblesDirecciones.Num() > 0)
    {
        // Elegir una dirección aleatoria entre las posibles
        IndiceActual = FMath::RandRange(0, PosiblesDirecciones.Num() - 1);
    }
}