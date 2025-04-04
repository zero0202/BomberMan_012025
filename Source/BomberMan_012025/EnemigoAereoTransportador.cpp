// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemigoAereoTransportador.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Materials/MaterialInterface.h"

AEnemigoAereoTransportador::AEnemigoAereoTransportador()
{

	PrimaryActorTick.bCanEverTick = true;
	//para asignar textura al bloque
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> ObjetoBloqueMaterial(TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/M_Tech_Panel.M_Tech_Panel'"));
	if (ObjetoBloqueMaterial.Succeeded())
	{
		MeshEnemigo->SetMaterial(0, ObjetoBloqueMaterial.Object);

	}

	// Encontrar una partícula que simule vapor o niebla
	static ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleSystemAsset(TEXT("/Game/StarterContent/Particles/P_Steam_Lit.P_Steam_Lit"));
	if (ParticleSystemAsset.Succeeded())
	{
		ParticleSystem->SetTemplate(ParticleSystemAsset.Object);

		// Escalar el sistema de partículas para que sea más grande
		ParticleSystem->SetWorldScale3D(FVector(100.0f, 100.0f, 100.5f));
	}


	AnguloActual = 5000.0f;
}

void AEnemigoAereoTransportador::BeginPlay()
{
	Super::BeginPlay();

	
}

void AEnemigoAereoTransportador::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Movimiento en círculo
	AnguloActual += VelocidadAngular * DeltaTime;
	if (AnguloActual >= 360.f) AnguloActual -= 360.f;

	float Radians = FMath::DegreesToRadians(AnguloActual);
	FVector Centro = FVector(20000.0f, 8450.0f, AlturaFlotante); // centro del laberinto
	FVector Posicion = Centro + FVector(FMath::Cos(Radians) * Radio, FMath::Sin(Radians) * Radio, 1500.0f);

	SetActorLocation(Posicion);

	VerificarMontura();
}

void AEnemigoAereoTransportador::VerificarMontura()
{
	if (!bPersonajeMontado || !PersonajeActual) return;

	// Si la distancia del personaje al enemigo es muy grande, se soltó
	float Distancia = FVector::Dist(PersonajeActual->GetActorLocation(), GetActorLocation());

	if (Distancia > 20.f) // Puedes ajustar el umbral
	{
		// Liberar personaje
		PersonajeActual->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
		bPersonajeMontado = false;
		PersonajeActual = nullptr;
	}
}




