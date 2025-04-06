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

protected:

	float DefensaCaparazon;
	bool bEnCaparazon;

	UFUNCTION()
	void OnCollisionWithPlayer(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	void ActivarCaparazon();
	void CambiarDireccion();
};
