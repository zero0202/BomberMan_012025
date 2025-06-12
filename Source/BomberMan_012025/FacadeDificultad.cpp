// Fill out your copyright notice in the Description page of Project Settings.


#include "FacadeDificultad.h"
#include "Nivel_1.h"
#include "Nivel_2.h"
#include "Nivel_3.h"

// Sets default values
AFacadeDificultad::AFacadeDificultad()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Nivel1 = nullptr;
	Nivel2 = nullptr;
	Nivel3 = nullptr;
}

// Called when the game starts or when spawned
void AFacadeDificultad::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFacadeDificultad::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFacadeDificultad::IniciarNivel1()
{
	Nivel1 = GetWorld()->SpawnActor<ANivel_1>(ANivel_1::StaticClass());

}

void AFacadeDificultad::IniciarNivel2()
{
	Nivel2 = GetWorld()->SpawnActor<ANivel_2>(ANivel_2::StaticClass());
}

void AFacadeDificultad::IniciarNivel3()
{
	Nivel3 = GetWorld()->SpawnActor<ANivel_3>(ANivel_3::StaticClass());
}

