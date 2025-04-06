// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemigo.h"
#include "EnemigoTerrestreExplosivo.generated.h"

class USphereComponent;
/**
 * 
 */
UCLASS()
class BOMBERMAN_012025_API AEnemigoTerrestreExplosivo : public AEnemigo
{
	GENERATED_BODY()

public:
	AEnemigoTerrestreExplosivo();

protected:

	virtual void BeginPlay() override;

public:

	virtual void Tick(float DeltaTime) override;

protected:

    UPROPERTY(VisibleAnywhere)
    USphereComponent* CollisionComponent;
    FTimerHandle TimerReaparicion;

    // Guardar la clase para respawn
    TSubclassOf<AEnemigoTerrestreExplosivo> ClaseEnemigo;

    UFUNCTION()
    void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,bool bFromSweep, const FHitResult& SweepResult);

    void Destruir();

    void Respawn();
    void CambiarDireccion();

    
private:
  


    float Vida;
    float Danio;
    float VelocidadDeMovimiento;
    bool bMovimientoPermitido;

};
