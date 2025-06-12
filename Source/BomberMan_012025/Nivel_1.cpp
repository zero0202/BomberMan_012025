// Fill out your copyright notice in the Description page of Project Settings.


#include "Nivel_1.h"
#include "EnemigoAcuaticoSaltarin.h"
#include "EnemigoTerrestreTortuga.h"
#include "EnemigoAereoPatrullero.h"
#include "EnemigoSubterraneoEmboscador.h"
#include "Moneda.h"
#include "Engine/Engine.h"

// Sets default values
ANivel_1::ANivel_1()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	EVida = 100.0f; // Vida del enemigo
	
}

// Called when the game starts or when spawned
void ANivel_1::BeginPlay()
{
	Super::BeginPlay();
	
	GenerarEnemigosNivel();
	EnemigoVida();
	Monedas();
}

// Called every frame
void ANivel_1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void ANivel_1::GenerarEnemigosNivel()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Generando Objetos de Nivel 1"));

	//int tipoE = FMath::RandRange(1, 4);
	for (int i=0 ; i<=5; i++)
	{
		
			GetWorld()->SpawnActor<AEnemigoAcuaticoSaltarin>(AEnemigoAcuaticoSaltarin::StaticClass(), FVector(18900, 940, 0), FRotator(0, 0, 0));
	
			GetWorld()->SpawnActor<AEnemigoTerrestreTortuga>(AEnemigoTerrestreTortuga::StaticClass(), FVector(18900, 940, 300), FRotator(0, 0, 0));
		
			GetWorld()->SpawnActor<AEnemigoAereoPatrullero>(AEnemigoAereoPatrullero::StaticClass(), FVector(18800, 960, 0), FRotator(0, 0, 0));
		
			GetWorld()->SpawnActor<AEnemigoSubterraneoEmboscador>(AEnemigoSubterraneoEmboscador::StaticClass(), FVector(18100, 970, 0), FRotator(0, 0, 0));
		
		
	}
}

void ANivel_1::EnemigoVida()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("El enemigo tiene 50 de vida"));
}

void ANivel_1::Monedas()
{
	for (int i = 0; i <= 5; i++)
	{
		GetWorld()->SpawnActor<AMoneda>(AMoneda::StaticClass(), FVector(15930, 1210, 300), FRotator(0, 0, 0));
	}
}

