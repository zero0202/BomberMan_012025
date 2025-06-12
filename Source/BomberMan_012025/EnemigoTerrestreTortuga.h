// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemigo.h"
#include "EnemigoTerrestreTortuga.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN_012025_API AEnemigoTerrestreTortuga : public AEnemigo
{
	GENERATED_BODY()

public:

	AEnemigoTerrestreTortuga();

protected:

	virtual void BeginPlay() override;

public:

	virtual void Tick(float DeltaTime) override;

private:
	FVector ObjetivoSalto;
	bool bSaltando;
	float TiempoEnAire;
	float DuracionSalto;
	FVector PosicionInicial;
public:
	void IniciarSalto();
	FVector CalcularNuevoDestino();
};
