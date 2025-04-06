// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemigo.h"
#include "EnemigoAcuaticoMedusa.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN_012025_API AEnemigoAcuaticoMedusa : public AEnemigo
{
	GENERATED_BODY()
	
public:

	AEnemigoAcuaticoMedusa();

protected:

	virtual void BeginPlay() override;

public:

	virtual void Tick(float DeltaTime) override;

	float TiempoTotal;
	float FrecuenciaOndulacion;
	float AmplitudOndulacion;
	FVector DireccionMovimiento;

	void CambiarDireccion(); 
};
