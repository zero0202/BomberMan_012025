// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Teletransportador.h"
#include "Bloque.h"
#include "Enemigo.h"
#include "BomberMan_012025GameMode.generated.h"

UCLASS(minimalapi)
class ABomberMan_012025GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:

	ABomberMan_012025GameMode();

public:

	virtual void BeginPlay() override;


public:

	//Para bloque
	UPROPERTY()
	TArray<ABloque*> BloquesA; // Guarda todos los bloques generados
	TArray<TArray<int32>> MapaLaberinto; 
	void GenerarMapaDesdeCodigo();
	void GenerarLaberinto();
	void GenerarBloqueMovible();

	//para Eliminar bloques
	ABloque* BloqueActual = nullptr;
	FTimerHandle TimerEliminarBloque;
	FTimerHandle TimerInicialBloquesMadera;
	void EliminarBloque();
	void iniciarEliminarBloque();

public:

	//para enemigos
	UPROPERTY()
	TArray<AEnemigo*> EnemigosA;//GUARDA LOS ENEMIGOS 
	TArray<FVector> PuntosPatrullaLibres;
	void SpawnEnemigos();

	//para eliminar enemigos
	AEnemigo* EnemigoActual = nullptr;
	FTimerHandle TimerEliminarEnemigos;
	void EleminarEnemigos();

public:

	//para el teletransportador
	UPROPERTY()
	TArray<ATeletransportador*> TodasLasPuertas;
	TMap<AActor*, float> ActoresTeletransportados;
	void GenerarPortal();

public:
	
	void PosicionarJugadorAleatoriamente();
	FTimerHandle TimerPosicion;

	void ReemplazarBloqueInterno();
	FTimerHandle TimerReemplazoBloque; 
public:
	void GenerarMonedas();
	

};



