// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemigo.h"
#include "EnemigoAcuaticoSaltarin.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN_012025_API AEnemigoAcuaticoSaltarin : public AEnemigo
{
	GENERATED_BODY()
	
public:
	AEnemigoAcuaticoSaltarin();

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
