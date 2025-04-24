// Fill out your copyright notice in the Description page of Project Settings.


#include "Bloque.h"
#include "Components/StaticMeshComponent.h"
#include "Particles/ParticleSystemComponent.h"


// Sets default values
ABloque::ABloque()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Para la creacion de la malla 
	MeshBloque = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshBloque"));
	MeshBloque->SetupAttachment(RootComponent);
	RootComponent = MeshBloque;

	//Para las particulas
	Particulas = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Particulas"));
	Particulas->SetupAttachment(RootComponent);
	/*
	// Inicializar variables para la velocidad y la rotacion del bloque 
	FloatSpeed = 5.0f;
	RotationSpeed = 3.0f;

	// Inicializar variables para el movimiento del bloque
	bPuedeMoverse = FMath::RandBool();
	*/
	// Establecer el tamaño inicial del bloque
	AjustarTamano(FVector(9.0f, 9.0f, 13.0f));

}

// Called when the game starts or when spawned
void ABloque::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABloque::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	/*
	//para el movimiento
	if (bPuedeMoverse)
	{
		//para el movimiento de arriba abajo
		FVector NewLocation = GetActorLocation();
		NewLocation.Z += DireccionMovimiento * FloatSpeed;

		if (FMath::Abs(NewLocation.Z - PosicionInicial.Z) >= AmplitudMovimiento)
		{
			DireccionMovimiento *= -1; // Invertir dirección al alcanzar el límite
		}

		SetActorLocation(NewLocation);
	}
	*/
}
void ABloque::AjustarTamano(FVector NuevoTamano)
{
	MeshBloque->SetWorldScale3D(NuevoTamano);
}

