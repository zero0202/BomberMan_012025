// Copyright Epic Games, Inc. All Rights Reserved.

#include "BomberMan_012025GameMode.h"
#include "BomberMan_012025Character.h"
#include "UObject/ConstructorHelpers.h"
#include "GameFramework/Character.h"
#include "Engine/Engine.h"
#include "Bloque.h"
#include "Muro.h"
#include "BloqueAcero.h"
#include "BloqueMadera.h"
#include "BloqueLadrillo.h"
#include "BloqueConcreto.h"

ABomberMan_012025GameMode::ABomberMan_012025GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

}

void ABomberMan_012025GameMode::BeginPlay()
{
	Super::BeginPlay();

    // Mapa del laberinto:
   // 0 = vacío, 1 = madera, 2 = ladrillo, 3 = concreto, 4 = acero
    MapaLaberinto = {
        {4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
        {4, 0, 1, 0, 1, 0, 2, 0, 1, 4},
        {4, 1, 0, 0, 0, 0, 0, 1, 0, 4},
        {4, 0, 0, 3, 0, 3, 0, 0, 0, 4},
        {4, 1, 0, 0, 0, 0, 1, 0, 2, 4},
        {4, 0, 0, 2, 0, 2, 0, 0, 0, 4},
        {4, 1, 0, 0, 0, 0, 0, 1, 0, 4},
        {4, 0, 0, 3, 0, 3, 0, 0, 0, 4},
        {4, 2, 0, 0, 0, 0, 0, 2, 0, 4},
        {4, 4, 4, 4, 4, 4, 4, 4, 4, 4}
    };
    
    GenerarLaberinto();

    /*
    //PARA BLOQUE Y MURO INTERCALADOS
    GEngine->AddOnScreenDebugMessage(-1, -1, FColor::Red, TEXT("Generando bloques y muros intercalados"));

    const int totalBloques = 6; // Número total de bloques
    const int totalMuros = 6;   // Número total de muros
    const float espacio = 600.0f; // Espacio entre elementos

    TArray<ABloque*> BloquesArray;
    TArray<AMuro*> MurosArray;


    int bloqueCount = 0;
    int muroCount = 0;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 6; j++) 
        {
            FVector posicion(900.0f + j * espacio, 6000.0f - i * espacio, 5.0f);
            if ((i + j) % 2 == 0 && bloqueCount < totalBloques)
            {
                ABloque* Bloque = GetWorld()->SpawnActor<ABloque>(ABloque::StaticClass(), posicion, FRotator(0.0f, 0.0f, 0.0f));
                if (Bloque)
                {
                    BloquesArray.Add(Bloque);
                }
                bloqueCount++;

            }
            else if (muroCount < totalMuros)
            {
                AMuro* Muro = GetWorld()->SpawnActor<AMuro>(AMuro::StaticClass(), posicion, FRotator(0.0f, 0.0f, 0.0f));
				if (Muro)
				{
					MurosArray.Add(Muro);
				}
                muroCount++;
            }
        }
    }
    */
    /*
    // Asignar dos bloques para moverse
    if (BloquesArray.Num() >= 2)
    {
        BloquesArray[0]->bPuedeMoverse = true;
        BloquesArray[1]->bPuedeMoverse = true;
        BloquesArray[2]->bPuedeMoverse = true;
    }
    */
    /*
    // Asignar dos muros para girar
    if (MurosArray.Num() >= 2)
    {
        MurosArray[0]->bPuedeGirar = true;
        MurosArray[1]->bPuedeGirar = true;
    }

    //CREAR BLOQUES

	GetWorld()->SpawnActor < ABloqueLadrillo >(ABloqueLadrillo::StaticClass(),FVector(1000.0f, 500.0f, 5.0f), FRotator(0.0f, 0.0f, 0.0f));
	GetWorld()->SpawnActor < ABloqueMadera >(ABloqueMadera::StaticClass(), FVector(1000.0f, 500.0f, 5.0f), FRotator(0.0f, 0.0f, 0.0f));
	GetWorld()->SpawnActor < ABloqueConcreto >(ABloqueConcreto::StaticClass(), FVector(1000.0f, 500.0f, 5.0f), FRotator(0.0f, 0.0f, 0.0f));
	GetWorld()->SpawnActor < ABloqueAcero >(ABloqueAcero::StaticClass(), FVector(1000.0f, 500.0f, 5.0f), FRotator(0.0f, 0.0f, 0.0f));
    */



}


void ABomberMan_012025GameMode::GenerarLaberinto()
{
    const float Espaciado = 300.0f; // Tamaño del espacio entre bloques

    for (int32 Y = 0; Y < MapaLaberinto.Num(); ++Y)
    {
        for (int32 X = 0; X < MapaLaberinto[Y].Num(); ++X)
        {
            int32 Tipo = MapaLaberinto[Y][X];
            if (Tipo == 0) continue; // espacio vacío

            FVector Posicion = FVector(X * Espaciado, Y * Espaciado, 0.0f);
            FRotator Rotacion = FRotator::ZeroRotator;
            TSubclassOf<AActor> ClaseBloque = nullptr;

            switch (Tipo)
            {
            case 1: ClaseBloque = ABloqueMadera::StaticClass(); break;
            case 2: ClaseBloque = ABloqueLadrillo::StaticClass(); break;
            case 3: ClaseBloque = ABloqueConcreto::StaticClass(); break;
            case 4: ClaseBloque = ABloqueAcero::StaticClass(); break;
            default: break;
            }

            if (ClaseBloque)
            {
                AActor* BloqueSpawned = GetWorld()->SpawnActor<AActor>(ClaseBloque, Posicion, Rotacion);
                if (BloqueSpawned)
                {
                    BloquesA.Add(BloqueSpawned); // Por si los quieres mover más tarde
                }
            }
        }
    }


}
