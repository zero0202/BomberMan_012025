// Fill out your copyright notice in the Description page of Project Settings.


#include "FabricaBloques.h"
#include "BloqueAcero.h"
#include "BloqueMadera.h"
#include "BloqueLadrillo.h"
#include "BloqueConcreto.h"
#include "BloqueArena.h"
#include "BloqueLava.h"
#include "BloqueElectrico.h"
#include "BloquePegajoso.h"
#include "BloqueHielo.h"
#include "BloqueHongo.h"
// Sets default values
AFabricaBloques::AFabricaBloques()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFabricaBloques::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFabricaBloques::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
/*
ABloque* AFabricaBloques::CrearBloques(FString TipoBloques, FVector Posicion, FRotator Rotacion)
{
	if (TipoBloques.Equals("Acero")) {
		return GetWorld()->SpawnActor<ABloqueAcero>(ABloqueAcero::StaticClass(), Posicion, FRotator::ZeroRotator);
		
	}
	else if (TipoBloques.Equals("Ladrillo")) {
		return GetWorld()->SpawnActor<ABloqueLadrillo>(ABloqueLadrillo::StaticClass(), Posicion, FRotator::ZeroRotator);

	}


}
*/
