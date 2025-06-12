// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemigo.h"
#include "EnemigoSubterraneoEmboscador.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN_012025_API AEnemigoSubterraneoEmboscador : public AEnemigo
{
	GENERATED_BODY()
	
public:

	AEnemigoSubterraneoEmboscador();

protected:

	virtual void BeginPlay() override;

public:

	virtual void Tick(float DeltaTime) override;
private:
	TArray<FVector> PuntosPatrulla;
	int32 IndiceActual;
	float VelocidadPatrulla;
	float AlturaVueloPa;
	void CambiarDireccion();
	void volarP(float DeltaTime);
};
