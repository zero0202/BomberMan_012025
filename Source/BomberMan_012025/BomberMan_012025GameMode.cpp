// Copyright Epic Games, Inc. All Rights Reserved.

#include "BomberMan_012025GameMode.h"
#include "BomberMan_012025Character.h"
#include "UObject/ConstructorHelpers.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "Components/CapsuleComponent.h"
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
#include "BloqueMovil.h"
#include "Enemigo.h"
#include "Teletransportador.h"
#include "EnemigoAereoTransportador.h"
#include "EnemigoAereoPatrullero.h"
#include "EnemigoTerrestreExplosivo.h"
#include "EnemigoTerrestreTortuga.h"
#include "EnemigoSubterraneoGolem.h"
#include "EnemigoSubterraneoEmboscador.h"
#include "EnemigoAcuaticoSaltarin.h"
#include "EnemigoAcuaticoMedusa.h" 
#include "Moneda.h"
#include "IPrototypeBloque.h"

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
/*
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
*/
    GenerarMapaDesdeCodigo();
    GenerarLaberinto();
	//GenerarBloqueMovible();
    PosicionarJugadorAleatoriamente();
    GenerarPortal();
   // SpawnEnemigos();
	GenerarEnemigos();
	//GenerarMonedas();
	ClonarBloque();

	//---------------------TEMPORIZADORES DEL JUEGO------------------
	//para eliminar bloque administrador de tiempo
	GetWorld()->GetTimerManager().SetTimer(TimerInicialBloquesMadera, this, &ABomberMan_012025GameMode::iniciarEliminarBloque, 10.0f, true);

    //para eliminar enemigos
	GetWorld()->GetTimerManager().SetTimer(TimerEliminarEnemigos, this, &ABomberMan_012025GameMode::EleminarEnemigos, 3.0f, true);

    //para reemplazar bloques
    GetWorld()->GetTimerManager().SetTimer(TimerReemplazoBloque, this, &ABomberMan_012025GameMode::ReemplazarBloqueInterno, 10.0f, true);

    //para posicionar aleatoriamente al jugador luego de generar el laberinto
    GetWorld()->GetTimerManager().SetTimer(TimerPosicion,this, &ABomberMan_012025GameMode::PosicionarJugadorAleatoriamente,0.1f,false);
   
	
}
void ABomberMan_012025GameMode::GenerarMapaDesdeCodigo()
{
    
    int Columnas = 49;
    int Filas = 49;

    int TColumnas = Columnas + 1;
    int TFilas = Filas + 1;
    int Y;
    int X;

    //inicializamos la matriz
    MapaLaberinto.SetNum(TFilas);
    for (Y = 0; Y < TFilas; Y++)
    {
        MapaLaberinto[Y].SetNum(TColumnas);
        for ( X = 0; X < TColumnas; X++)
        {
            // Bordes de acero
            if (X == 0 || Y == 0 || X == TColumnas - 1 || Y == TFilas - 1)
            {
                MapaLaberinto[Y][X] = 4; // Acero
            }
            else
            {
                MapaLaberinto[Y][X] = -1; // Se define al poner 
            }
        }
    }
    //FIntPoint para almacenar los dos puntos x, ya
    //int32, int32
    TSet<FIntPoint> Visitadas;//evita repetidos y bucles infinitos 
    TArray<FIntPoint> Pila;//explora 
    auto Direcciones = { FIntPoint(0, -2), FIntPoint(0, 2), FIntPoint(-2, 0), FIntPoint(2, 0) };

    //verifica si esta dentro del 49
    auto Valido = [&](int X, int Y) -> bool
        {
            return X > 0 && Y > 0 && X < Columnas && Y < Filas;
        };

    FIntPoint Inicio(1, 1);
    Pila.Push(Inicio);
    MapaLaberinto[Inicio.Y][Inicio.X] = 0;
    Visitadas.Add(Inicio);

	// Mientras haya elementos en la pila
    while (Pila.Num() > 0)
    {
        FIntPoint Actual = Pila.Top();
        TArray<FIntPoint> Vecinos;

        for (FIntPoint Dir : Direcciones)
        {
            FIntPoint Nuevo = Actual + Dir;
            if (Valido(Nuevo.X, Nuevo.Y) && !Visitadas.Contains(Nuevo))
            {
                Vecinos.Add(Nuevo);
            }
        }

        if (Vecinos.Num() > 0)
        {
            FIntPoint Elegido = Vecinos[FMath::RandRange(0, Vecinos.Num() - 1)];

            // Abrir camino
            int MidX = (Actual.X + Elegido.X) / 2;
            int MidY = (Actual.Y + Elegido.Y) / 2;

            MapaLaberinto[Elegido.Y][Elegido.X] = 0;
            MapaLaberinto[MidY][MidX] = 0;

            Pila.Push(Elegido);
            Visitadas.Add(Elegido);
        }
        else
        {
			Pila.Pop(); // Regresar al anterior
        } 
    }

    // Muros internos: 40% izquierda madera, resto ladrillo
    int BloqueColumnas = TColumnas * 0.4f;
    int BloqueFilas = TFilas * 0.3f;

    // Bloques internos
    for (Y = 1; Y < TFilas - 1; Y++)
    {
        for (X = 1; X < TColumnas - 1; X++)
        {
            if (MapaLaberinto[Y][X] == -1)
            {
                if (X < BloqueColumnas && Y < BloqueFilas)
                {
                    MapaLaberinto[Y][X] = 1; // Solo madera
                }
                else
                {
                    MapaLaberinto[Y][X] = 4; // Solo ladrillo
                }
            }
        }
    }

    // Entrada y salida
    MapaLaberinto[1][0] = 0;
    MapaLaberinto[TFilas - 2][TColumnas - 1] = 0;


    /*
    // Definir centro del mapa
int32 MaderaAncho = TotalAncho * 0.4f;
int32 MaderaAlto = TotalAlto * 0.4f;

int32 InicioX = (TotalAncho - MaderaAncho) / 2;
int32 InicioY = (TotalAlto - MaderaAlto) / 2;
int32 FinX = InicioX + MaderaAncho;
int32 FinY = InicioY + MaderaAlto;

// Muros internos: madera en el centro, ladrillo en el resto
for (int32 Y = 1; Y < TotalAlto - 1; ++Y)
{
    for (int32 X = 1; X < TotalAncho - 1; ++X)
    {
        if (MapaLaberinto[Y][X] == -1)
        {
            if (X >= InicioX && X < FinX && Y >= InicioY && Y < FinY)
            {
                MapaLaberinto[Y][X] = 1; // madera en el centro
            }
            else
            {
                MapaLaberinto[Y][X] = 2; // ladrillo en el resto
            }
        }
    }
}
    */

}

void ABomberMan_012025GameMode::GenerarLaberinto()
{

    float Espaciado = 900.0f;

    //las filas y columnas se estan creando directamente se derivan automaticamente 
    // El tamaño lo decide el contenido del array.
    //puedo hacer un laberinto más grande o más pequeño solo cambiando el array, sin tocar nada más del código
    
    // Recorre cada fila del mapa del laberinto (eje Y)
    for (int Y = 0; Y < MapaLaberinto.Num(); ++Y)
    {
        // Recorre cada columna dentro de la fila actual (eje X)
        for (int X = 0; X < MapaLaberinto[Y].Num(); ++X)
        {
            // Obtiene el tipo de bloque que hay en la posición (Y, X)
            int Tipo = MapaLaberinto[Y][X];

            // Si el tipo es 0, se considera espacio vacío y no se genera nada
            if (Tipo == 0) {
            
                FVector PosicionLibre = FVector(X * Espaciado, Y * Espaciado, 0.0f); // ajusta altura si deseas
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

void ABomberMan_012025GameMode::GenerarBloqueMovible()
{
    for (int i = 0; i < 2; ++i)
    {
        if (PuntosPatrullaLibres.Num() == 0) break;

        FVector Pos = PuntosPatrullaLibres[FMath::RandRange(0, PuntosPatrullaLibres.Num() - 1)];
        ABloqueMovil* Bloque = GetWorld()->SpawnActor<ABloqueMovil>(ABloqueMovil::StaticClass(), Pos, FRotator::ZeroRotator);

        if (Bloque)
        {
            // Parámetros personalizados
            Bloque->TiempoEntreMovimientos = 0.7f;
            Bloque->DistanciaRecorrido = FMath::RandRange(2700.f, 4500.f); // entre 3 y 5 celdas

            // Esencial para que se mueva correctamente
            Bloque->PosicionInicial = Pos;
            Bloque->GameModeRef = this;  // muy importante
        }
    }
}

void ABomberMan_012025GameMode::ClonarBloque()
{

    TArray<AActor*> Resultados;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABloqueMadera::StaticClass(), Resultados);

    if (Resultados.Num() > 0)
    {
        ABloqueMadera* Prototipo = Cast<ABloqueMadera>(Resultados[0]);
        if (Prototipo)
        {
            FVector PosDestino(2300, 4300, 1400); // donde clonarlo
            AActor* Clon = Prototipo->Clonar(GetWorld(), PosDestino);
            //FVector PosDes(3600, 4300, 1400);
            //AActor* clo1 = Prototipo->Clonar(GetWorld(),PosDes);
        }
    }
}
void ABomberMan_012025GameMode::GenerarEnemigos()
{
	Dificultad = GetWorld()->SpawnActor<AFacadeDificultad>(AFacadeDificultad::StaticClass());
	//Dificultad->IniciarNivel1();
	Dificultad->IniciarNivel2();
	//Dificultad->IniciarNivel3();

}
void ABomberMan_012025GameMode::GenerarPortal()
{
    ATeletransportador* Puerta1 = GetWorld()->SpawnActor<ATeletransportador>(ATeletransportador::StaticClass(), FVector(800.0f, 880.0f, 10.0f), FRotator::ZeroRotator);
    ATeletransportador* Puerta2 = GetWorld()->SpawnActor<ATeletransportador>(ATeletransportador::StaticClass(), FVector(41680.0f, 880.0f, 10.0f), FRotator::ZeroRotator);
    ATeletransportador* Puerta3 = GetWorld()->SpawnActor<ATeletransportador>(ATeletransportador::StaticClass(), FVector(800.0f, 42390.0f, 10.0f), FRotator::ZeroRotator);
    ATeletransportador* Puerta4 = GetWorld()->SpawnActor<ATeletransportador>(ATeletransportador::StaticClass(), FVector(41800.0f, 42520.0f, 10.0f), FRotator::ZeroRotator);
    ATeletransportador* Puerta5 = GetWorld()->SpawnActor<ATeletransportador>(ATeletransportador::StaticClass(), FVector(800.0f, 20520.0f, 10.0f), FRotator::ZeroRotator);
    ATeletransportador* Puerta6 = GetWorld()->SpawnActor<ATeletransportador>(ATeletransportador::StaticClass(), FVector(41800.0f, 18000.0f, 10.0f), FRotator::ZeroRotator);

    TodasLasPuertas = { Puerta1, Puerta2, Puerta3, Puerta4, Puerta5, Puerta6 };

    for (ATeletransportador* Puerta : TodasLasPuertas)
    {
        if (Puerta)
        {
            Puerta->CompuertasConectadas = TodasLasPuertas;
            Puerta->SetGameMode(this);
        }
    }

    int IndexFija1 = FMath::RandRange(0, TodasLasPuertas.Num() - 1);

    int IndexFija2;
    do {
        IndexFija2 = FMath::RandRange(0, TodasLasPuertas.Num() - 1);
    } while (IndexFija2 == IndexFija1); // asegurarse de que no sea el mismo índice

    TodasLasPuertas[IndexFija1]->bEsPuertaFija = true;
    TodasLasPuertas[IndexFija2]->bEsPuertaFija = true;

}

void ABomberMan_012025GameMode::EliminarBloque()
{

    TArray<ABloque*> BloquesMadera;

    for (ABloque* Bloque : BloquesA)
    {
        if (Bloque && Bloque->IsA(ABloqueMadera::StaticClass()))
        {
            BloquesMadera.Add(Bloque);
        }
    }

    if (BloquesMadera.Num() > 0)
    {
        int32 Aleatorio = FMath::RandRange(0, BloquesMadera.Num() - 1);
        BloqueActual = BloquesMadera[Aleatorio];

        if (BloqueActual)
        {
            BloqueActual->Destroy();
            BloquesA.Remove(BloqueActual);
        }
    }

    /*
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
        int32 Aleatorio = FMath::RandRange(0, BloquesEliminables.Num() - 1);
        BloqueActual = BloquesEliminables[Aleatorio];

        if (BloqueActual)
        {
            BloqueActual->Destroy();
            BloquesA.Remove(BloqueActual); // Opcional: para que no lo intentes eliminar otra vez
        }
    }
    */
}

void ABomberMan_012025GameMode::iniciarEliminarBloque()
{
	// Iniciar el temporizador para eliminar bloques
	GetWorld()->GetTimerManager().SetTimer(TimerEliminarBloque, this, &ABomberMan_012025GameMode::EliminarBloque, 3.0f, true);
    GetWorld()->GetTimerManager().SetTimer(TimerEliminarBloque, this, &ABomberMan_012025GameMode::EliminarBloque, 4.0f, true);
    GetWorld()->GetTimerManager().SetTimer(TimerEliminarBloque, this, &ABomberMan_012025GameMode::EliminarBloque, 3.0f, true);

}

void ABomberMan_012025GameMode::EleminarEnemigos()
{
    
    if (EnemigosA.Num() <= 4) return; 

    // Crear lista de enemigos validos
    TArray<AEnemigo*> EnemigosEliminables;
    for (AEnemigo* Enemigo : EnemigosA)
    {
        if (IsValid(Enemigo) && !Enemigo->IsActorBeingDestroyed())
        {
            EnemigosEliminables.Add(Enemigo);
        }
    }

    if (EnemigosEliminables.Num() > 0)
    {
        int AleatorioE = FMath::RandRange(0, EnemigosEliminables.Num() - 1);
        AEnemigo* EnemigoAEliminar = EnemigosEliminables[AleatorioE];

        if (IsValid(EnemigoAEliminar))
        {
            EnemigoAEliminar->Destroy();
            EnemigosA.Remove(EnemigoAEliminar);
        }
    }

    // Detener el timer cuando quedan 4
    if (EnemigosA.Num() <= 4)
    {
        GetWorld()->GetTimerManager().ClearTimer(TimerEliminarEnemigos);
    }
   
}
/*
void ABomberMan_012025GameMode::SpawnEnemigos()
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

    for (int32 i = 0; i < 5; ++i)
    {
        int32 TipoEnemigo = FMath::RandRange(1, 5);
        FVector Posicion = ObtenerPosicionAleatoria();

        switch (TipoEnemigo)
        {
        case 1:
            GetWorld()->SpawnActor<AEnemigoTerrestreExplosivo>(AEnemigoTerrestreExplosivo::StaticClass(), Posicion, FRotator::ZeroRotator);
            break;
        case 2:
            GetWorld()->SpawnActor<AEnemigoAcuaticoSaltarin>(AEnemigoAcuaticoSaltarin::StaticClass(), Posicion, FRotator::ZeroRotator);
            break;
        case 3:
            GetWorld()->SpawnActor<AEnemigoAcuaticoMedusa>(AEnemigoAcuaticoMedusa::StaticClass(), Posicion, FRotator::ZeroRotator);
            break;
        case 4:
            GetWorld()->SpawnActor<AEnemigoSubterraneoEmboscador>(AEnemigoSubterraneoEmboscador::StaticClass(), Posicion, FRotator::ZeroRotator);
            break;
        case 5:
            GetWorld()->SpawnActor<AEnemigoSubterraneoGolem>(AEnemigoSubterraneoGolem::StaticClass(), Posicion, FRotator::ZeroRotator);
            break;
        }
    }
    // Spawnear 3 enemigos en posiciones fijas
    GetWorld()->SpawnActor<AEnemigoAereoTransportador>(AEnemigoAereoTransportador::StaticClass(), FVector(2000, 2000, 300), FRotator::ZeroRotator);
    GetWorld()->SpawnActor<AEnemigoTerrestreTortuga>(AEnemigoTerrestreTortuga::StaticClass(), FVector(3000, 3000, 100), FRotator::ZeroRotator);
    GetWorld()->SpawnActor<AEnemigoAereoPatrullero>(AEnemigoAereoPatrullero::StaticClass(), FVector(4000, 4000, 300), FRotator::ZeroRotator);

    

}
*/
void ABomberMan_012025GameMode::PosicionarJugadorAleatoriamente()
{
    TArray<FVector> PosicionesValidas;
    float Espaciado = 900.0f;
    int32 NumFilas = MapaLaberinto.Num();
    int32 NumColumnas = MapaLaberinto[0].Num();
    float DistanciaMinima = FLT_MAX;

    for (int Y = 1; Y < NumFilas - 1; ++Y)
    {
        for (int X = 1; X < NumColumnas - 1; ++X)
        {
            // Buscamos celdas vacías adyacentes a bloques de madera
            if (MapaLaberinto[Y][X] == 0)
            {
                // Revisar las 4 direcciones alrededor
                bool CercaDeMadera =
                    MapaLaberinto[Y + 1][X] == 1 || MapaLaberinto[Y - 1][X] == 1 ||
                    MapaLaberinto[Y][X + 1] == 1 || MapaLaberinto[Y][X - 1] == 1;

                if (CercaDeMadera)
                {
                    // Calcular la distancia al borde más cercano
                    int DistIzq = X;
                    int DistDer = NumColumnas - 1 - X;
                    int DistArriba = Y;
                    int DistAbajo = NumFilas - 1 - Y;
                    int DistanciaABorde = FMath::Min3(DistIzq, DistDer, FMath::Min(DistArriba, DistAbajo));

                    FVector Pos = FVector(X * Espaciado, Y * Espaciado, 0.0f);

                    if (DistanciaABorde < DistanciaMinima)
                    {
                        PosicionesValidas.Empty(); // Limpiar para nueva distancia mínima
                        DistanciaMinima = DistanciaABorde;
                    }

                    if (DistanciaABorde == DistanciaMinima)
                    {
                        PosicionesValidas.Add(Pos);
                    }
                }
            }
        }
    }

    if (PosicionesValidas.Num() > 0)
    {
        FVector PosicionElegida = PosicionesValidas[FMath::RandRange(0, PosicionesValidas.Num() - 1)];

        // Ajustar altura
        PosicionElegida.Z = 100.f;
        APawn* Jugador = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
        if (Jugador)
        {
            ACharacter* JugadorChar = Cast<ACharacter>(Jugador);
            if (JugadorChar && JugadorChar->GetCapsuleComponent())
            {
                PosicionElegida.Z = JugadorChar->GetCapsuleComponent()->GetScaledCapsuleHalfHeight();
            }

            Jugador->SetActorLocation(PosicionElegida);
            UE_LOG(LogTemp, Warning, TEXT("Jugador posicionado correctamente en: %s"), *PosicionElegida.ToString());
        }
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("No se encontró ninguna posición válida para el jugador."));
    }

}
void ABomberMan_012025GameMode::ReemplazarBloqueInterno()
{
    TArray<ABloque*> BloquesInternos;

    for (ABloque* Bloque : BloquesA)
    {
        if (!Bloque) continue;

        FVector Pos = Bloque->GetActorLocation();

        // Convertimos a índice de matriz dividiendo por el espaciado
        int X = FMath::RoundToInt(Pos.X / 900.f);
        int Y = FMath::RoundToInt(Pos.Y / 900.f);

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
    int Index = FMath::RandRange(0, BloquesInternos.Num() - 1);
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

    int NuevoIndex = FMath::RandRange(0, TiposPosibles.Num() - 1);
    TSubclassOf<ABloque> NuevaClase = TiposPosibles[NuevoIndex];

    // Spawneamos el nuevo bloque
    ABloque* NuevoBloque = GetWorld()->SpawnActor<ABloque>(NuevaClase, Posicion, Rotacion);
    if (NuevoBloque)
    {
        BloquesA.Add(NuevoBloque);
        UE_LOG(LogTemp, Warning, TEXT("Bloque reemplazado en "), *Posicion.ToString());
    }
}
/*
void ABomberMan_012025GameMode::GenerarMonedas()
{
    if (PuntosPatrullaLibres.Num() > 0)
    {
        FVector Pos = PuntosPatrullaLibres[FMath::RandRange(0, PuntosPatrullaLibres.Num() - 1)];
        Pos.Z = 100.f; // altura visible
        GetWorld()->SpawnActor<AMoneda>(AMoneda::StaticClass(), Pos, FRotator::ZeroRotator);
    }
}
*/