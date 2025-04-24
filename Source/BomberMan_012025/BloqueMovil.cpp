// Fill out your copyright notice in the Description page of Project Settings.


#include "BloqueMovil.h"
#include "BomberMan_012025GameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInterface.h"

ABloqueMovil::ABloqueMovil()
{
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> ObjetoMeshBloqueArena(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	if (ObjetoMeshBloqueArena.Succeeded())
	{
		MeshBloque->SetStaticMesh(ObjetoMeshBloqueArena.Object);

		MeshBloque->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
		MeshBloque->SetWorldScale3D(FVector(1.5f, 1.9f, 1.2f));
	}
	//para asignar textura
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> ObjetoBloqueAceroMaterial(TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/FosforoRosa.FosforoRosa'"));
	if (ObjetoBloqueAceroMaterial.Succeeded())
	{
		MeshBloque->SetMaterial(0, ObjetoBloqueAceroMaterial.Object);
	}


}

void ABloqueMovil::BeginPlay()
{
	Super::BeginPlay();
	PosicionInicial = GetActorLocation();

	GameModeRef = Cast<ABomberMan_012025GameMode>(UGameplayStatics::GetGameMode(GetWorld()));

	// Genera las 4 direcciones posibles
	DireccionesValidas = { FIntPoint(1,0), FIntPoint(-1,0), FIntPoint(0,1), FIntPoint(0,-1) };

}

void ABloqueMovil::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    if (!GameModeRef || !bPuedeMoverse) return;

    TiempoTranscurrido += DeltaTime;
    if (TiempoTranscurrido < TiempoEntreMovimientos) return;
    TiempoTranscurrido = 0.f;

    FVector Pos = GetActorLocation();
    int32 X = FMath::RoundToInt(Pos.X / 900.f);
    int32 Y = FMath::RoundToInt(Pos.Y / 900.f);

    // Direcciones del movimiento en zigzag (→ ↓ ← ↓ ...)
    FIntPoint Direccion;
    switch (CurrentMovement)
    {
    case 1: Direccion = FIntPoint(1, 0); break;   // derecha
    case 2: Direccion = FIntPoint(0, 1); break;   // abajo
    case 3: Direccion = FIntPoint(-1, 0); break;  // izquierda
    case 4: Direccion = FIntPoint(0, 1); break;   // abajo
    }

    int32 NX = X + Direccion.X;
    int32 NY = Y + Direccion.Y;

    if (NX >= 0 && NY >= 0 && NY < GameModeRef->MapaLaberinto.Num() && NX < GameModeRef->MapaLaberinto[NY].Num())
    {
        if (GameModeRef->MapaLaberinto[NY][NX] == 0)
        {
            FVector Destino = FVector(NX * 900.f, NY * 900.f, Pos.Z);
            float Distancia = FVector::Dist(PosicionInicial, Destino);

            if (Distancia <= DistanciaRecorrido)
            {
                SetActorLocation(Destino);

                CurrentMovement = (CurrentMovement % 4) + 1; // ciclo 1→2→3→4→1
            }
        }
    }
}
