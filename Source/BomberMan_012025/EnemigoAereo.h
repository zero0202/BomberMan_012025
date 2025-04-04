// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemigo.h"
#include "EnemigoAereo.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN_012025_API AEnemigoAereo : public AEnemigo
{
	GENERATED_BODY()
	
public:

	AEnemigoAereo();

protected:
	virtual void BeginPlay() override;
public:
	virtual void Tick(float DeltaTime) override;
	
	

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UParticleSystemComponent* ParticleSystem;

	UFUNCTION(BlueprintCallable)
	void AjustarTamanoA(FVector NuevoTamano);
	// Altura a la que debe mantenerse volando
	UPROPERTY(EditAnywhere, Category = "Movimiento Aéreo")
	float AlturaVuelo = 500.0f;

	// Movimiento vertical suave
	virtual void Volar(float DeltaTime);
};
