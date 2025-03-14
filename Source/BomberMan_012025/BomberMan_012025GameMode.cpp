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


    //PARA BLOQUE Y MURO INTERCALADOS
    GEngine->AddOnScreenDebugMessage(-1, -1, FColor::Red, TEXT("Generando bloques y muros intercalados"));

    const int totalBloques = 5; // N�mero total de bloques
    const int totalMuros = 5;   // N�mero total de muros
    const float espacio = 500.0f; // Espacio entre elementos

    TArray<ABloque*> BloquesArray;
    TArray<AMuro*> MurosArray;


    int bloqueCount = 0;
    int muroCount = 0;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 5; j++) 
        {
            FVector posicion(570.0f + j * espacio, 3000.0f - i * espacio, 5.0f);
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

    // Asignar dos bloques para moverse
    if (BloquesArray.Num() >= 2)
    {
        BloquesArray[0]->bPuedeMoverse = true;
        BloquesArray[1]->bPuedeMoverse = true;
    }

    // Asignar dos muros para girar
    if (MurosArray.Num() >= 2)
    {
        MurosArray[0]->bPuedeGirar = true;
        MurosArray[1]->bPuedeGirar = true;
    }

	/* 
    int numeroBloqueConMovimiento = 0;
    const int filas = 5; // N�mero de filas
    const int columnas = 5; // N�mero de columnas
    const float espacio = 500.0f; // Espacio entre bloques

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            // Calcular la posici�n de cada bloque
            FVector posicion(570.0f + j * espacio, 3000.0f - i * espacio, 5.0f);
            ABloque* Bloque = GetWorld()->SpawnActor<ABloque>(ABloque::StaticClass(), posicion, FRotator(0.0f, 0.0f, 0.0f));

            if (Bloque->bPuedeMoverse)
            {
                numeroBloqueConMovimiento++;
            }

            // Limitar el n�mero de bloques que pueden moverse
            if (numeroBloqueConMovimiento >= 5)
            {
                Bloque->bPuedeMoverse = false;
            }
        }
    }

    //PARA MURO
    const int filasM = 3; // N�mero de filas
    const int columnasM = 3; // N�mero de columnas
    const float espacioM = 550.0f; // Espacio entre bloques

    for (int i = 0; i < filasM; i++)
    {
        for (int j = 0; j < columnasM; j++)
        {
            // Calcular la posici�n de cada Muro
            FVector posicion(400.0f + j * espacioM, 1500.0f - i * espacioM, 5.0f);
            AMuro* Muro = GetWorld()->SpawnActor<AMuro>(AMuro::StaticClass(), posicion, FRotator(0.0f, 0.0f, 0.0f));
        }
    }


    
   
	//PARA BLOQUE DE ACERO

    float espacioBA = 500.0f;

    for (int i = 0; i < 2; i++)
    {
        FVector posicionAcero(700.0f + i * espacioBA, 1680.0f, 5.0f);
        ABloqueAcero* BloqueAcero1 = GetWorld()->SpawnActor<ABloqueAcero>(ABloqueAcero::StaticClass(), posicionAcero, FRotator::ZeroRotator);
    }
    //PARA BLOQUE MADERA
	float espacioBMA = 500.0f;
    for (int i = 0 ; i < 2; i++)
    {
		FVector posicionMadera(2260.0f + i * espacioBMA, 400.0f, 5.0f);
		ABloqueMadera* BloqueMadera1 = GetWorld()->SpawnActor<ABloqueMadera>(ABloqueMadera::StaticClass(), posicionMadera, FRotator::ZeroRotator);
        if (BloqueMadera1)
        {
			BloqueMadera1->bAbriendo = true;
        }
    }
    */

    // Espacio entre bloques
        float espacioMBA = 500.0f;

    // Generar bloques de acero en una cuadr�cula 2x2
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            FVector posicionAcero(700.0f + j * espacioMBA, 1680.0f + i * espacioMBA, 5.0f);
            ABloqueAcero* BloqueAcero1 = GetWorld()->SpawnActor<ABloqueAcero>(ABloqueAcero::StaticClass(), posicionAcero, FRotator::ZeroRotator);
        }
    }

    // Generar bloques de madera en una cuadr�cula 2x2
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            FVector posicionMadera(1800.0f + j * espacioMBA, 1690.0f + i * espacioMBA, 5.0f);
            ABloqueMadera* BloqueMadera1 = GetWorld()->SpawnActor<ABloqueMadera>(ABloqueMadera::StaticClass(), posicionMadera, FRotator::ZeroRotator);
            if (BloqueMadera1)
            {
                BloqueMadera1->bAbriendo = true; // Iniciar el movimiento del bloque de madera
            }
        }
    }
}
