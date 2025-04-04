// Fill out your copyright notice in the Description page of Project Settings.


#include "BloqueArena.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInterface.h"
#include "Particles/ParticleSystemComponent.h"
#include "Particles/ParticleSystem.h"
#include "GameFramework/Character.h"
#include "Engine/Engine.h" 

ABloqueArena::ABloqueArena()
{
	PrimaryActorTick.bCanEverTick = true;


	static ConstructorHelpers::FObjectFinder<UStaticMesh> ObjetoMeshBloqueAcero(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	if (ObjetoMeshBloqueAcero.Succeeded())
	{
		MeshBloque->SetStaticMesh(ObjetoMeshBloqueAcero.Object);

		MeshBloque->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	}
	//para asignar textura
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> ObjetoBloqueAceroMaterial(TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/M_Metal_Gold.M_Metal_Gold'"));
	if (ObjetoBloqueAceroMaterial.Succeeded())
	{
		MeshBloque->SetMaterial(0, ObjetoBloqueAceroMaterial.Object);

	}

	// Partículas de polvo/sand
	ParticulasArena = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticulasArena"));
	ParticulasArena->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UParticleSystem> ArenaFX(TEXT("/Game/StarterContent/Particles/P_Steam_Lit.P_Steam_Lit")); // usa este como polvo temporal
	if (ArenaFX.Succeeded())
	{
		ParticulasArena->SetTemplate(ArenaFX.Object);
	}
	// Configurar la colisión
	MeshBloque->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	MeshBloque->OnComponentBeginOverlap.AddDynamic(this, &ABloqueArena::OnOverlapBegin);  // Detectar cuando empieza la colisión


	TiempoArena = 0.f;
	TiempoHundimiento = 0.f;
	bEstaHundido = false;
}

void ABloqueArena::BeginPlay()
{
	Super::BeginPlay();
	PosicionInicial = GetActorLocation();
	ParticulasArena->Activate();
}

void ABloqueArena::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TiempoArena += DeltaTime;

	// Movimiento suave tipo onda senoidal (como si "respirara arena")
	float Amplitud = 5.0f;
	float Frecuencia = 3.5f;

	float DesplazamientoZ = FMath::Sin(TiempoArena * Frecuencia) * Amplitud;

	FVector NuevaPos = PosicionInicial;
	NuevaPos.Z = PosicionInicial.Z + DesplazamientoZ;

	SetActorLocation(NuevaPos);

	// Si el bloque está hundido, moverlo hacia abajo
	if (bEstaHundido)
	{
		TiempoHundimiento += DeltaTime;
		float DesplazamientoHundido = FMath::Lerp(0.f, -50.f, TiempoHundimiento / 3.f);  // Hundir 50 unidades hacia abajo en 3 segundos
		FVector NuevaPosHundido = PosicionInicial;
		NuevaPosHundido.Z += DesplazamientoHundido;

		SetActorLocation(NuevaPosHundido);

		// Una vez que el bloque haya llegado al fondo, evitar más movimiento
		if (TiempoHundimiento >= 3.f)
		{
			bEstaHundido = false;  // El bloque dejó de hundirse
		}
	}
}

void ABloqueArena::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Verificar si el actor que colisiona es el personaje
	ACharacter* Personaje = Cast<ACharacter>(OtherActor);
	if (Personaje)
	{
		// Mostrar un mensaje en el log
		UE_LOG(LogTemp, Warning, TEXT("¡Personaje tocó el bloque de arena!"));

		// Iniciar el hundimiento
		bEstaHundido = true;
		TiempoHundimiento = 1.f;
	}
}

