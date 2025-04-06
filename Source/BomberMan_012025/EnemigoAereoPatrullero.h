// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemigo.h"
#include "EnemigoAereoPatrullero.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN_012025_API AEnemigoAereoPatrullero : public AEnemigo
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

	//direccion patrullaje
	int32 IndiceActual;
	float VelocidadPatrulla;
	float AlturaVueloPa;
	void CambiarDireccion();
	void volarP(float DeltaTime);
	UFUNCTION()
	void OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,const FHitResult& SweepResult);

};
