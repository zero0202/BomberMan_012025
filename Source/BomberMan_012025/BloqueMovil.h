// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Bloque.h"
#include "BloqueMovil.generated.h"

class ABomberMan_012025GameMode;
/**
 * 
 */
UCLASS()
class BOMBERMAN_012025_API ABloqueMovil : public ABloque
{
	GENERATED_BODY()
	
public:
	
	ABloqueMovil();

protected:

	virtual void BeginPlay() override;

public:

	virtual void Tick(float DeltaTime) override;
public:

    FVector PosicionInicial;
    float Velocidad = 300.f;
    float TiempoEntreMovimientos = 1.0f;
    float TiempoTranscurrido = 0.0f;
    float DistanciaRecorrido = 4500.f;
    int32 CurrentMovement = 1;
    TArray<FIntPoint> DireccionesValidas;
    int32 IndiceDireccion = 0;

    bool bPuedeMoverse = true;

    ABomberMan_012025GameMode* GameModeRef;
   
};
