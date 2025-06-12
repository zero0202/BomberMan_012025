// Fill out your copyright notice in the Description page of Project Settings.


#include "Nivel_2.h"
#include "EnemigoAcuaticoSaltarin.h"
#include "EnemigoAcuaticoMedusa.h"
#include "EnemigoSubterraneoEmboscador.h"
#include "Moneda.h"

// Sets default values
ANivel_2::ANivel_2()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	EVida = 200.0f; // Vida del enemigo
}

// Called when the game starts or when spawned
void ANivel_2::BeginPlay()
{
	Super::BeginPlay();
	
	GenerarEnemigosNivel();
	EnemigoVida();
	Monedas();
}

// Called every frame
void ANivel_2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ANivel_2::GenerarEnemigosNivel()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Generando Objetos de Nivel 2"));
	for (int i = 0; i <= 10; i++)
	{
		GetWorld()->SpawnActor<AEnemigoAcuaticoSaltarin>(AEnemigoAcuaticoSaltarin::StaticClass(), FVector(18900, 940, 0), FRotator(0, 0, 0));
		GetWorld()->SpawnActor<AEnemigoAcuaticoMedusa>(AEnemigoAcuaticoMedusa::StaticClass(), FVector(18900, 940, 300), FRotator(0, 0, 0));
		GetWorld()->SpawnActor<AEnemigoSubterraneoEmboscador>(AEnemigoSubterraneoEmboscador::StaticClass(), FVector(18100, 970, 0), FRotator(0, 0, 0));
	}
}

void ANivel_2::EnemigoVida()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("El enemigo tiene 100 de vida"));
}

void ANivel_2::Monedas()
{

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Generando Monedas en Nivel 2"));
	for (int i = 0; i <= 4; i++)
	{
		GetWorld()->SpawnActor<AMoneda>(AMoneda::StaticClass(), FVector(18900 + i * 100, 940, 0), FRotator(0, 0, 0));
	}
}

