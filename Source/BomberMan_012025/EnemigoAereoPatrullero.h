// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemigoAereo.h"
#include "EnemigoAereoPatrullero.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN_012025_API AEnemigoAereoPatrullero : public AEnemigoAereo
{
	GENERATED_BODY()
public:
	AEnemigoAereoPatrullero();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FVector> PuntosPatrulla;

	int32 IndiceActual;
	float VelocidadPatrulla;
	void CambiarDireccion();
};
