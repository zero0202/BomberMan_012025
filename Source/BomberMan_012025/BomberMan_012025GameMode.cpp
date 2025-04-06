// Copyright Epic Games, Inc. All Rights Reserved.

#include "BomberMan_012025GameMode.h"
#include "BomberMan_012025Character.h"
#include "UObject/ConstructorHelpers.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/Engine.h"
#include "Bloque.h"
#include "Muro.h"
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
#include "Teletransportador.h"
#include "EnemigoAereoTransportador.h"
#include "EnemigoAereoPatrullero.h"
#include "EnemigoTerrestreExplosivo.h"
#include "EnemigoTerrestreTortuga.h"
#include "EnemigoSubterraneoGolem.h"
#include "EnemigoSubterraneoEmboscador.h"
#include "EnemigoAcuaticoSaltarin.h"
#include "EnemigoAcuaticoMedusa.h" 

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

    //portal
    FTransform Transform1, Transform2;
    Transform1.SetLocation(FVector(640.f, 325.f, 10.f)); // ejemplo
    Transform2.SetLocation(FVector(6999.f, 8053.f, 10.f));

    Compuerta1 = GetWorld()->SpawnActor<ATeletransportador>(ATeletransportador::StaticClass(), Transform1);
    Compuerta2 = GetWorld()->SpawnActor<ATeletransportador>(ATeletransportador::StaticClass(), Transform2);

    Compuerta1->CompuertaDestino = Compuerta2;
    Compuerta2->CompuertaDestino = Compuerta1;

    Compuerta1->SetGameMode(this);
    Compuerta2->SetGameMode(this);
   

    // Mapa del laberinto:
   // 0 = vacío, 1 = madera, 2 = ladrillo, 3 = concreto, 4 = acero 5 = lava, 6 = arena, 7 = electrico, 8 = pegajoso, 9 = hielo, 10 = hongo
    MapaLaberinto = {
{4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4},
{4,0,0,0,0,4,0,1,1,0,0,4,0,1,0,4,0,0,0,1,0,0,1,0,4,4,0,0,0,0,4,0,7,7,0,0,4,0,7,0,4,0,0,0,7,0,7,7,0,4},
{4,0,4,4,4,4,0,2,4,4,0,4,0,0,0,4,2,4,0,1,0,0,2,0,4,4,0,4,4,4,4,0,2,4,4,0,4,0,0,0,4,2,4,0,7,0,0,2,0,4},
{4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,1,0,0,1,1,1,0,4,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,1,0,0,7,7,7,0,4},
{4,0,4,0,1,1,1,1,0,1,0,4,4,4,4,0,0,0,0,0,0,0,2,0,4,4,0,4,0,1,1,1,1,0,1,0,4,4,4,4,0,0,0,0,0,0,0,2,0,4},
{4,0,4,0,1,0,0,0,0,0,4,0,2,0,4,4,2,4,2,0,1,1,1,0,4,4,0,4,0,1,0,0,0,0,0,4,0,2,0,4,4,2,4,2,0,8,8,8,0,4},
{4,2,4,4,2,4,4,0,2,4,4,0,1,0,2,0,0,4,2,0,1,0,0,0,4,4,2,4,4,2,4,4,0,2,4,4,0,1,0,2,0,0,4,2,0,1,0,0,0,4},
{4,0,1,0,0,0,2,0,4,0,1,0,0,0,4,0,0,1,1,1,1,1,1,0,4,4,0,1,0,0,0,2,0,4,0,1,0,0,0,4,0,0,9,9,9,9,9,9,0,4},
{4,0,4,2,4,4,4,2,2,0,1,1,1,0,2,0,1,1,1,0,0,0,1,0,4,4,0,4,2,4,4,4,2,2,0,1,1,1,0,2,0,9,9,10,0,0,0,1,0,4},
{4,0,1,0,2,0,2,4,4,0,0,0,2,0,4,0,0,1,0,0,1,0,2,0,4,4,0,1,0,2,0,2,4,4,0,0,0,2,0,4,0,0,9,0,0,1,0,2,0,4},
{4,2,4,0,1,0,1,0,1,0,1,0,1,0,4,0,0,1,0,0,1,0,1,0,4,4,2,4,0,1,0,1,0,1,0,1,0,1,0,4,0,0,1,0,0,1,0,1,0,4},
{4,0,4,0,0,0,2,0,0,0,1,0,0,0,4,4,4,4,2,0,1,1,1,0,4,4,0,4,0,0,0,2,0,0,0,1,0,0,0,4,4,4,4,2,0,1,1,1,0,4},
{4,0,4,0,1,1,0,1,1,1,1,0,0,0,0,0,1,0,0,4,0,0,0,0,4,4,0,4,0,1,1,0,1,1,1,1,0,0,0,0,0,1,0,0,4,0,0,0,0,4},
{4,0,0,0,2,0,4,0,4,0,0,0,0,3,4,4,4,0,1,1,1,1,1,0,4,4,0,0,0,2,0,4,0,4,0,0,0,0,3,4,4,4,0,1,1,1,1,1,0,4},
{4,2,0,0,1,0,4,0,4,0,1,0,0,0,0,4,0,0,0,2,4,0,1,0,4,4,2,0,0,1,0,4,0,4,0,1,0,0,0,0,4,0,0,0,2,4,0,1,0,4},
{4,0,4,0,1,0,4,0,0,0,1,0,4,4,0,1,0,1,0,0,0,0,1,0,4,4,0,4,0,1,0,4,0,0,0,1,0,4,4,0,1,0,1,0,0,0,0,1,0,4},
{4,0,1,1,1,0,1,1,1,0,1,1,1,0,0,1,0,2,2,2,2,0,4,4,4,4,0,1,1,1,0,1,1,1,0,1,1,1,0,0,1,0,2,2,2,2,0,4,4,4},
{4,0,1,0,2,0,0,0,1,0,0,0,2,0,0,4,4,4,0,4,4,4,4,0,4,4,0,1,0,2,0,0,0,1,0,0,0,2,0,0,4,4,4,0,4,4,4,4,0,4},
{4,0,1,0,1,0,1,0,1,0,1,0,1,0,0,4,0,0,0,2,4,2,4,0,4,4,0,1,0,1,0,1,0,1,0,1,0,1,0,0,4,0,0,0,2,4,2,4,0,4},
{4,0,1,0,4,0,2,0,1,1,1,0,0,0,0,4,0,1,1,0,0,0,4,0,4,4,0,1,0,4,0,2,0,1,1,1,0,0,0,0,4,0,1,1,0,0,0,4,0,4},
{4,0,1,0,4,0,1,0,0,0,1,1,1,0,0,0,0,1,0,0,2,0,4,0,4,4,0,1,0,4,0,1,0,0,0,1,1,1,0,0,0,0,1,0,0,2,0,4,0,4},
{4,0,4,4,4,0,3,4,4,0,4,4,2,4,2,4,4,2,0,1,1,0,2,4,4,4,0,4,4,4,0,3,4,4,0,4,4,2,4,2,4,4,2,0,1,1,0,2,4,4},
{4,2,4,0,2,0,1,0,1,0,4,4,1,0,0,1,0,1,1,0,0,0,0,0,4,4,2,4,0,2,0,1,0,1,0,4,4,1,0,0,1,0,1,1,0,0,0,0,0,4},
{4,0,1,0,1,0,2,0,1,0,4,0,0,0,4,0,0,1,0,0,0,0,1,0,4,4,0,1,0,1,0,2,0,1,0,4,0,0,0,4,0,0,1,0,0,0,0,1,0,4},
{4,0,2,0,4,0,4,0,4,4,4,0,2,0,4,2,4,1,0,2,2,4,4,0,4,4,0,2,0,4,0,4,0,4,4,4,0,2,0,4,2,4,1,0,2,2,4,4,0,4},
{4,2,4,0,4,0,1,0,1,0,4,4,0,0,1,0,2,0,1,0,4,2,2,0,4,4,2,4,0,4,0,1,0,1,0,4,4,0,0,1,0,2,0,1,0,4,2,2,0,4},
{4,0,4,0,2,0,0,4,0,0,0,2,2,0,1,0,0,4,4,4,0,1,1,0,4,4,0,4,0,2,0,0,4,0,0,0,2,2,0,1,0,0,4,4,4,0,1,1,0,4},
{4,0,4,0,4,0,0,2,2,0,0,0,0,0,1,0,0,4,0,4,0,0,1,0,4,4,0,4,0,4,0,0,2,2,0,0,0,0,0,1,0,0,4,0,4,0,0,1,0,4},
{4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4},
{4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4},
{4,0,0,0,0,4,0,1,1,0,0,4,0,1,0,4,0,0,0,1,0,0,1,0,4,4,0,0,0,0,4,0,1,1,0,0,4,0,1,0,4,0,0,0,1,0,0,1,0,4},
{4,0,4,4,4,4,0,2,4,4,0,4,0,0,0,4,2,4,0,1,0,0,2,0,4,4,0,4,4,4,4,0,2,4,4,0,4,0,0,0,4,2,4,0,1,0,0,2,0,4},
{4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,1,0,0,1,1,1,0,4,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,1,0,0,1,1,1,0,4},
{4,0,4,0,1,1,1,1,0,1,0,4,4,4,4,0,0,0,0,0,0,0,2,0,4,4,0,4,0,1,1,1,1,0,1,0,4,4,4,4,0,0,0,0,0,0,0,2,0,4},
{4,0,4,0,1,0,0,0,0,0,4,0,2,0,4,4,2,4,2,0,1,1,1,0,4,4,0,4,0,1,0,0,0,0,0,4,0,2,0,4,4,2,4,2,0,1,1,1,0,4},
{4,2,4,4,2,4,4,0,2,4,4,0,1,0,2,0,0,4,2,0,1,0,0,0,4,4,2,4,4,2,4,4,0,2,4,4,0,1,0,2,0,0,4,2,0,1,0,0,0,4},
{4,0,1,0,0,0,2,0,4,0,1,0,0,0,4,0,0,1,1,1,1,1,1,0,4,4,0,1,0,0,0,2,0,4,0,1,0,0,0,4,0,0,1,1,1,1,1,1,0,4},
{4,0,4,2,4,4,4,2,2,0,1,1,1,0,2,0,1,1,1,0,0,0,1,0,4,4,0,4,2,4,4,4,2,2,0,1,1,1,0,2,0,1,1,1,0,0,0,1,0,4},
{4,0,1,0,2,0,2,4,4,0,0,0,2,0,4,0,0,1,0,0,1,0,2,0,4,4,0,1,0,2,0,2,4,4,0,0,0,2,0,4,0,0,1,0,0,1,0,2,0,4},
{4,2,4,0,1,0,1,0,1,0,1,0,1,0,4,0,0,1,0,0,1,0,1,0,4,4,2,4,0,1,0,1,0,1,0,1,0,1,0,4,0,0,1,0,0,1,0,1,0,4},
{4,0,4,0,0,0,2,0,0,0,1,0,0,0,4,4,4,4,2,0,1,1,1,0,4,4,0,4,0,0,0,2,0,0,0,1,0,0,0,4,4,4,4,2,0,1,1,1,0,4},
{4,0,4,0,1,1,0,1,1,1,1,0,0,0,0,0,1,0,0,4,0,0,0,0,4,4,0,4,0,1,1,0,1,1,1,1,0,0,0,0,0,1,0,0,4,0,0,0,0,4},
{4,0,0,0,2,0,4,0,4,0,0,0,0,3,4,4,4,0,1,1,1,1,1,0,4,4,0,0,0,2,0,4,0,4,0,0,0,0,3,4,4,4,0,1,1,1,1,1,0,4},
{4,2,0,0,1,0,4,0,4,0,1,0,0,0,0,4,0,0,0,2,4,0,1,0,4,4,2,0,0,1,0,4,0,4,0,1,0,0,0,0,4,0,0,0,2,4,0,1,0,4},
{4,0,4,0,1,0,4,0,0,0,1,0,4,4,0,1,0,1,0,0,0,0,1,0,4,4,0,4,0,1,0,4,0,0,0,1,0,4,4,0,1,0,1,0,0,0,0,1,0,4},
{4,0,1,1,1,0,1,1,1,0,1,1,1,0,0,1,0,2,2,2,2,0,4,4,4,4,0,1,1,1,0,1,1,1,0,1,1,1,0,0,1,0,2,2,2,2,0,4,4,4},
{4,0,1,0,2,0,0,0,1,0,0,0,2,0,0,4,4,4,0,4,4,4,4,0,4,4,0,1,0,2,0,0,0,1,0,0,0,2,0,0,4,4,4,0,4,4,4,4,0,4},
{4,0,1,0,1,0,1,0,1,0,1,0,1,0,0,4,0,0,0,2,4,2,4,0,4,4,0,1,0,1,0,1,0,1,0,1,0,1,0,0,4,0,0,0,2,4,2,4,0,4},
{4,0,1,0,4,0,2,0,1,1,1,0,0,0,0,4,0,1,1,0,0,0,0,0,4,4,0,1,0,4,0,2,0,1,1,1,0,0,0,0,4,0,1,1,0,0,0,4,0,4},
{4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4}
};
     
    GenerarLaberinto();
    SpawnEnemigosAereos();

	//temporizador para eliminar bloque administrador de tiempo
	GetWorld()->GetTimerManager().SetTimer(TimerEliminarBloque, this, &ABomberMan_012025GameMode::EliminarBloque, 3.0f, true);


    //Parte de la pregunta 1
    // ✅ Timer para posicionar aleatoriamente al jugador luego de generar el laberinto
    //GetWorld()->GetTimerManager().SetTimer(TimerPosicion,this, &ABomberMan_012025GameMode::PosicionarJugadorAleatoriamente,0.1f,false);
        //--------------------------------
        //Parte de la pregunta 2
   
    GetWorld()->GetTimerManager().SetTimer(TimerReemplazoBloque,this,&ABomberMan_012025GameMode::ReemplazarBloqueInterno,1.0f,true);

}


void ABomberMan_012025GameMode::GenerarLaberinto()
{

    //int32 Filas = MapaLaberinto.Num();              // = 50
    //int32 Columnas = MapaLaberinto[0].Num();        // = 50
    // Define el espacio entre bloques del laberinto
    float Espaciado = 900.0f;

    //las filas y columnas se estan creando directamente se derivan automaticamente 
    // El tamaño lo decide el contenido del array.
    //puedo hacer un laberinto más grande o más pequeño solo cambiando el array, sin tocar nada más del código
    
    // Recorre cada fila del mapa del laberinto (eje Y)
    for (int32 Y = 0; Y < MapaLaberinto.Num(); ++Y)
    {
        // Recorre cada columna dentro de la fila actual (eje X)
        for (int32 X = 0; X < MapaLaberinto[Y].Num(); ++X)
        {
            // Obtiene el tipo de bloque que hay en la posición (Y, X)
            int32 Tipo = MapaLaberinto[Y][X];

            // Si el tipo es 0, se considera espacio vacío y no se genera nada
            if (Tipo == 0) {
            
               FVector PosicionLibre = FVector(X * Espaciado, Y * Espaciado, 500.0f); // ajusta altura si deseas
               PuntosPatrullaLibres.Add(PosicionLibre);
               continue;

            }

            //creacion directamente desde que se genera x y y, en la pocion 0 0 0 por defecto
            FVector Posicion = FVector(X * Espaciado, Y * Espaciado, 0.0f);
            FRotator Rotacion = FRotator::ZeroRotator;
            TSubclassOf<AActor> ClaseBloque = nullptr;

            switch (Tipo)
            {
            case 1: ClaseBloque = ABloqueMadera::StaticClass(); break;
            case 2: ClaseBloque = ABloqueLadrillo::StaticClass(); break;
            case 3: ClaseBloque = ABloqueConcreto::StaticClass(); break;
            case 4: ClaseBloque = ABloqueAcero::StaticClass(); break;
			case 5: ClaseBloque = ABloqueLava::StaticClass(); break;
			case 6: ClaseBloque = ABloqueArena::StaticClass(); break;
			case 7: ClaseBloque = ABloqueElectrico::StaticClass(); break;
			case 8: ClaseBloque = ABloquePegajoso::StaticClass(); break;
			case 9: ClaseBloque = ABloqueHielo::StaticClass(); break;
			case 10: ClaseBloque = ABloqueHongo::StaticClass(); break;
            default: break;
            }

            if (ClaseBloque)
            {
                ABloque* BloqueSpawned = GetWorld()->SpawnActor<ABloque>(ClaseBloque, Posicion, Rotacion);
                if (BloqueSpawned)
                {
              
                    BloquesA.Add(BloqueSpawned); // Guarda el bloque en un array para acceso futuro
                }
            }
        }
    }


}

void ABomberMan_012025GameMode::EliminarBloque()
{
    // Crear un array temporal con solo bloques que se pueden eliminar (NO de acero)
    TArray<ABloque*> BloquesEliminables;

    for (ABloque* Bloque : BloquesA)
    {
        if (!Bloque) continue;

        // Verificamos que no sea un bloque de acero
        //IsA se utiliza para verificar   que sea de la clase bloque
        if (!Bloque->IsA(ABloqueAcero::StaticClass()))
        {
            BloquesEliminables.Add(Bloque);
        }
    }

    // Si hay bloques eliminables disponibles
    if (BloquesEliminables.Num() > 0)
    {
        int32 IndexAleatorio = FMath::RandRange(0, BloquesEliminables.Num() - 1);
        BloqueActual = BloquesEliminables[IndexAleatorio];

        if (BloqueActual)
        {
            BloqueActual->Destroy();
            BloquesA.Remove(BloqueActual); // Opcional: para que no lo intentes eliminar otra vez
        }
    }
}


void ABomberMan_012025GameMode::SpawnEnemigosAereos()
{

    if (PuntosPatrullaLibres.Num() < 8) return;

    TArray<FVector> PosicionesUsadas;
    auto ObtenerPosicionAleatoria = [&]() -> FVector
        {
            FVector Posicion;
            do
            {
                Posicion = PuntosPatrullaLibres[FMath::RandRange(0, PuntosPatrullaLibres.Num() - 1)];
            } while (PosicionesUsadas.Contains(Posicion));

            PosicionesUsadas.Add(Posicion);
            return Posicion;
        };

    // Spawnear 5 enemigos aleatorios en posiciones vacías
    GetWorld()->SpawnActor<AEnemigoTerrestreExplosivo>(AEnemigoTerrestreExplosivo::StaticClass(), ObtenerPosicionAleatoria(), FRotator::ZeroRotator);
    GetWorld()->SpawnActor<AEnemigoAcuaticoSaltarin>(AEnemigoAcuaticoSaltarin::StaticClass(), ObtenerPosicionAleatoria(), FRotator::ZeroRotator);
    GetWorld()->SpawnActor<AEnemigoAcuaticoMedusa>(AEnemigoAcuaticoMedusa::StaticClass(), ObtenerPosicionAleatoria(), FRotator::ZeroRotator);
    GetWorld()->SpawnActor<AEnemigoSubterraneoEmboscador>(AEnemigoSubterraneoEmboscador::StaticClass(), ObtenerPosicionAleatoria(), FRotator::ZeroRotator);
    GetWorld()->SpawnActor<AEnemigoSubterraneoGolem>(AEnemigoSubterraneoGolem::StaticClass(), ObtenerPosicionAleatoria(), FRotator::ZeroRotator);

    // Spawnear 3 enemigos en posiciones fijas
    GetWorld()->SpawnActor<AEnemigoAereoTransportador>(AEnemigoAereoTransportador::StaticClass(), FVector(2000, 2000, 300), FRotator::ZeroRotator);
    GetWorld()->SpawnActor<AEnemigoTerrestreTortuga>(AEnemigoTerrestreTortuga::StaticClass(), FVector(3000, 3000, 100), FRotator::ZeroRotator);
    AEnemigoAereoPatrullero* Patrullero = GetWorld()->SpawnActor<AEnemigoAereoPatrullero>(AEnemigoAereoPatrullero::StaticClass(), FVector(4000, 4000, 300), FRotator::ZeroRotator);

    if (Patrullero)
    {
        Patrullero->PuntosPatrulla = PuntosPatrullaLibres;
    }
}
/*
void ABomberMan_012025GameMode::PosicionarJugadorAleatoriamente()
{
    TArray<FVector> PosicionesLibres;
    float Espaciado = 1000.f;

    for (int32 Y = 0; Y < MapaLaberinto.Num(); ++Y)
    {
        for (int32 X = 0; X < MapaLaberinto[Y].Num(); ++X)
        {
            if (MapaLaberinto[Y][X] == 0) // celda vacía
            {
                FVector Posicion = FVector(X * Espaciado, Y * Espaciado, 0.0f);
                PosicionesLibres.Add(Posicion);
            }
        }
    }

    if (PosicionesLibres.Num() > 0)
    {
        int32 IndexAleatorio = FMath::RandRange(0, PosicionesLibres.Num() - 1);
        FVector PosicionInicial = PosicionesLibres[IndexAleatorio];
        PosicionInicial.Z = 0.f; // altura sobre el piso

        APawn* Jugador = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
        if (Jugador)
        {
            Jugador->SetActorLocation(PosicionInicial);
            UE_LOG(LogTemp, Warning, TEXT("✅ BomberMan reubicado en: %s"), *PosicionInicial.ToString());
        }
        else
        {
            UE_LOG(LogTemp, Error, TEXT("❌ No se encontró el Pawn del jugador."));
        }
    }

}
*/
//parte de la pregunta 2
void ABomberMan_012025GameMode::ReemplazarBloqueInterno()
{
    TArray<ABloque*> BloquesInternos;

    for (ABloque* Bloque : BloquesA)
    {
        if (!Bloque) continue;

        FVector Pos = Bloque->GetActorLocation();

        // Convertimos a índice de matriz dividiendo por el espaciado
        int32 X = FMath::RoundToInt(Pos.X / 1000.f);
        int32 Y = FMath::RoundToInt(Pos.Y / 1000.f);

        // Si está en el borde, lo ignoramos
        if (X <= 0 || Y <= 0 ||
            X >= MapaLaberinto[0].Num() - 1 ||
            Y >= MapaLaberinto.Num() - 1)
        {
            continue;
        }

        // Agregamos solo bloques que no sean acero y estén dentro del laberinto
        if (!Bloque->IsA(ABloqueAcero::StaticClass()))
        {
            BloquesInternos.Add(Bloque);
        }
    }

    if (BloquesInternos.Num() == 0) return;

    // Elegimos uno al azar
    int32 Index = FMath::RandRange(0, BloquesInternos.Num() - 1);
    ABloque* BloqueAReemplazar = BloquesInternos[Index];

    if (!BloqueAReemplazar) return;

    FVector Posicion = BloqueAReemplazar->GetActorLocation();
    FRotator Rotacion = BloqueAReemplazar->GetActorRotation();

    // Eliminamos el actual
    BloquesA.Remove(BloqueAReemplazar);
    BloqueAReemplazar->Destroy();

    // Elegimos una clase distinta al tipo actual
    TArray<TSubclassOf<ABloque>> TiposPosibles = {ABloqueMadera::StaticClass(),ABloqueLadrillo::StaticClass(), ABloqueConcreto::StaticClass(),ABloquePegajoso::StaticClass(), ABloqueLava::StaticClass(),ABloqueHielo::StaticClass(), ABloqueArena::StaticClass(),ABloqueElectrico::StaticClass(),ABloqueHongo::StaticClass()};

    // Filtrar para evitar repetir tipo
    TSubclassOf<ABloque> ClaseActual = BloqueAReemplazar->GetClass();
    TiposPosibles.Remove(ClaseActual);

    int32 NuevoIndex = FMath::RandRange(0, TiposPosibles.Num() - 1);
    TSubclassOf<ABloque> NuevaClase = TiposPosibles[NuevoIndex];

    // Spawneamos el nuevo bloque
    ABloque* NuevoBloque = GetWorld()->SpawnActor<ABloque>(NuevaClase, Posicion, Rotacion);
    if (NuevoBloque)
    {
        BloquesA.Add(NuevoBloque);
        UE_LOG(LogTemp, Warning, TEXT("Bloque reemplazado en "), *Posicion.ToString());
    }
}