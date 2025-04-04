// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemigo.h"

AEnemigo::AEnemigo()
{
	PrimaryActorTick.bCanEverTick = true;

	// Crear el Static Mesh
	MeshEnemigo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshEnemigo"));
	MeshEnemigo->SetupAttachment(RootComponent);

}

void AEnemigo::BeginPlay()
{
	Super::BeginPlay();
}
void AEnemigo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}