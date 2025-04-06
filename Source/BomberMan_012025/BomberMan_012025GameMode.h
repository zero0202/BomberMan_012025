// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Teletransportador.h"
#include "Bloque.h"
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

	UPROPERTY()
	TArray<ABloque*> BloquesA; // Guarda todos los bloques generados
	TArray<TArray<int32>> MapaLaberinto; 

	ABloque* BloqueActual = nullptr;
	FTimerHandle TimerEliminarBloque;

	void GenerarLaberinto();
	void EliminarBloque();

	//portal para abajo
	UPROPERTY()
	TMap<AActor*, float> ActoresTeletransportados;

	UPROPERTY()
	ATeletransportador* Compuerta1;

	UPROPERTY()
	ATeletransportador* Compuerta2;


	void SpawnEnemigosAereos();

	TArray<FVector> PuntosPatrullaLibres;


	//PRIMER_PARCIAL
public:

	//parte de la pregunta 1
	void PosicionarJugadorAleatoriamente();
	FTimerHandle TimerPosicion; // <- Agregalo junto a los otros timers
	//----

	//parte de la pregunta 2
	FTimerHandle TimerReemplazoBloque; 
	UFUNCTION()
	void ReemplazarBloqueInterno(); 
	

};



