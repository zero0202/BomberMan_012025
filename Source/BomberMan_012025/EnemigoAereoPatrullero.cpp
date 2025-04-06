// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemigoAereoPatrullero.h"
#include "Particles/ParticleSystemComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Character.h"
#include "Engine/World.h"


AEnemigoAereoPatrullero::AEnemigoAereoPatrullero()
{
    PrimaryActorTick.bCanEverTick = true;

    static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Cylinder.Shape_Cylinder'"));
    if (MeshAsset.Succeeded())
    {
        MeshEnemigo->SetStaticMesh(MeshAsset.Object);
    }


    static ConstructorHelpers::FObjectFinder<UMaterialInterface> ObjetoBloqueMaterial(TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/EfectoF.EfectoF'"));
    if (ObjetoBloqueMaterial.Succeeded())
    {
        MeshEnemigo->SetMaterial(0, ObjetoBloqueMaterial.Object);

    }

    // Encontrar una partícula que simule vapor o niebla
    static ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleSystemAsset(TEXT("/Script/Engine.ParticleSystem'/Game/StarterContent/Particles/P_Fire.P_Fire'"));
    if (ParticleSystemAsset.Succeeded())
    {
        ParticleSystem->SetTemplate(ParticleSystemAsset.Object);

        // Escalar el sistema de partículas para que sea más grande
        ParticleSystem->SetWorldScale3D(FVector(2.0f, 3.0f, 3.5f));
    }


    // Inicializar la colisión
    USphereComponent* ColliderComponent = CreateDefaultSubobject<USphereComponent>(TEXT("ColliderComponent"));
    ColliderComponent->SetupAttachment(RootComponent);
    ColliderComponent->InitSphereRadius(0.5f);  // Ajustar el tamaño de la esfera para detectar el personaje
    ColliderComponent->SetCollisionProfileName(TEXT("Trigger"));  // Configura como Trigger para colisiones
    ColliderComponent->OnComponentBeginOverlap.AddDynamic(this, &AEnemigoAereoPatrullero::OnComponentBeginOverlap); // Añadir el evento de colisión

    AjustarTamano(FVector(3.0f, 3.0f, 1.5f));
    GetCharacterMovement()->GravityScale = 0.0f;

    IndiceActual = 0;
    VelocidadPatrulla = 600.f;
    AlturaVueloPa = 100;

}

void AEnemigoAereoPatrullero::BeginPlay()
{
    Super::BeginPlay();

    // Establecer la posición inicial del enemigo
    FVector PosicionInicialEnemigo = FVector(2440.0f, 4370.0f, 100.0f);  // Cambia estas coordenadas según lo que necesites
    SetActorLocation(PosicionInicialEnemigo);
    // Si los puntos de patrullaje están vacíos, añadir el punto inicial
    if (PuntosPatrulla.Num() == 0)
    {
        PuntosPatrulla.Add(GetActorLocation()); // Empieza desde la posición inicial
    }
}

void AEnemigoAereoPatrullero::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime); // mantiene altura

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

void AEnemigoAereoPatrullero::CambiarDireccion()
{
    float Angulo = FMath::RandRange(0, 3) * 90.0f; // 0, 90, 180, 270
    SetActorRotation(FRotator(0, Angulo, 0));
}

void AEnemigoAereoPatrullero::volarP(float DeltaTime)
{
    // Mueve suavemente el actor a la AlturaVuelo definida
    FVector PosicionActual = GetActorLocation();
    PosicionActual.Z = AlturaVueloPa;

    FVector NuevaPosicion = FMath::VInterpTo(GetActorLocation(), PosicionActual, DeltaTime, 2.0f);
    SetActorLocation(NuevaPosicion);
}

void AEnemigoAereoPatrullero::OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    // Verifica si el actor con el que colisionamos es el personaje
    ABomberMan_012025Character* Personaje = Cast<ABomberMan_012025Character>(OtherActor);
 
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT(" choco con el patrullero"));

 
}
