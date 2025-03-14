// Fill out your copyright notice in the Description page of Project Settings.


#include "BloqueLadrillo.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInterface.h"
// Sets default values
ABloqueLadrillo::ABloqueLadrillo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshBloqueLadrillo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshBloqueLadrillo"));
	MeshBloqueLadrillo->SetupAttachment(RootComponent);

	
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ObjetoMeshBloqueLadrillo(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	if (ObjetoMeshBloqueLadrillo.Succeeded())
	{
		MeshBloqueLadrillo->SetStaticMesh(ObjetoMeshBloqueLadrillo.Object);
		MeshBloqueLadrillo->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	}
	//para asignar textura al bloque
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> ObjetoBloqueLadrilloMaterial(TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/M_CobbleStone_Smooth.M_CobbleStone_Smooth'"));
	if (ObjetoBloqueLadrilloMaterial.Succeeded())
	{
		MeshBloqueLadrillo->SetMaterial(0, ObjetoBloqueLadrilloMaterial.Object);
	}

	// Inicializar variables
	velocidad = 0.8f; // Velocidad de movimiento
	amplitud = 50.0f;   // Distancia maxima de apertura
	
	AjustarTamanoAcero(FVector(2.0f, 2.0f, 2.0f));

}

// Called when the game starts or when spawned
void ABloqueLadrillo::BeginPlay()
{
	Super::BeginPlay();
	// Guardar la posici�n inicial en el eje Z
	PosicionInicial = GetActorLocation().Z;

}

// Called every frame
void ABloqueLadrillo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// Calcular la nueva posici�n en el eje Z
	FVector NewLocation = GetActorLocation();
	float Tiempo = GetWorld()->GetTimeSeconds(); // Tiempo actual del juego

	// Movimiento oscilatorio en el eje Z (arriba y abajo)
	NewLocation.Z = PosicionInicial + FMath::Sin(Tiempo * velocidad) * amplitud;

	// Actualizar la posici�n del actor
	SetActorLocation(NewLocation);

}

void ABloqueLadrillo::AjustarTamanoAcero(FVector NuevoTamano)
{
	MeshBloqueLadrillo->SetWorldScale3D(NuevoTamano);
}

