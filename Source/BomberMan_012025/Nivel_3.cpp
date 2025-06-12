// Fill out your copyright notice in the Description page of Project Settings.


#include "Nivel_3.h"
#include "EnemigoAcuaticoSaltarin.h"
#include "EnemigoAcuaticoMedusa.h"
#include "EnemigoSubterraneoEmboscador.h"
#include "EnemigoTerrestreTortuga.h"
#include "EnemigoAereoPatrullero.h"
#include "Moneda.h"
#include "Engine/Engine.h"

// Sets default values
ANivel_3::ANivel_3()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	EVida = 300.0f; // Vida del enemigo
}

// Called when the game starts or when spawned
void ANivel_3::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANivel_3::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ANivel_3::GenerarEnemigosNivel()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Generando Objetos de Nivel 3"));
	for (int i = 0; i <= 15; i++)
	{
		GetWorld()->SpawnActor<AEnemigoAcuaticoSaltarin>(AEnemigoAcuaticoSaltarin::StaticClass(), FVector(18900, 940, 0), FRotator(0, 0, 0));
		GetWorld()->SpawnActor<AEnemigoAcuaticoMedusa>(AEnemigoAcuaticoMedusa::StaticClass(), FVector(18900, 940, 300), FRotator(0, 0, 0));
		GetWorld()->SpawnActor<AEnemigoSubterraneoEmboscador>(AEnemigoSubterraneoEmboscador::StaticClass(), FVector(18100, 970, 0), FRotator(0, 0, 0));
		GetWorld()->SpawnActor<AEnemigoTerrestreTortuga>(AEnemigoTerrestreTortuga::StaticClass(), FVector(18100, 970, -300), FRotator(0, 0, 0));
		GetWorld()->SpawnActor<AEnemigoAereoPatrullero>(AEnemigoAereoPatrullero::StaticClass(), FVector(18800, 960, 0), FRotator(0, 0, 0));
	}
}

void ANivel_3::EnemigoVida()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("El enemigo tiene 300 de vida"));
}

void ANivel_3::Monedas()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Generando Monedas en Nivel 3"));
	for (int i = 0; i <= 2; i++)
	{
		GetWorld()->SpawnActor<AMoneda>(AMoneda::StaticClass(), FVector(18900 + i * 100, 940, 0), FRotator(0, 0, 0));
	}
}

