// Fill out your copyright notice in the Description page of Project Settings.


#include "BloquePegajoso.h"

ABloquePegajoso::ABloquePegajoso()
{
	PrimaryActorTick.bCanEverTick = true;


	static ConstructorHelpers::FObjectFinder<UStaticMesh> ObjetoMeshBloqueAcero(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	if (ObjetoMeshBloqueAcero.Succeeded())
	{
		MeshBloque->SetStaticMesh(ObjetoMeshBloqueAcero.Object);

		MeshBloque->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	}
	//para asignar textura
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> ObjetoBloqueAceroMaterial(TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/M_Glass.M_Glass'"));
	if (ObjetoBloqueAceroMaterial.Succeeded()) 
	{
		MeshBloque->SetMaterial(0, ObjetoBloqueAceroMaterial.Object);

	}

}

void ABloquePegajoso::BeginPlay()
{
	Super::BeginPlay();

}

void ABloquePegajoso::Tick(float DeltaTime)
{

	Super::Tick(DeltaTime);
}
