// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemigo.h"
#include "EnemigoAereoTransportador.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN_012025_API AEnemigoAereoTransportador : public AEnemigo
{
	GENERATED_BODY()

public:
	AEnemigoAereoTransportador();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	float VelocidadVuelo;
	float AlturaFlotante;
	float AlturaVuelo;

	// Ruta circular
	float Radio;
	float VelocidadAngular ; // grados por segundo
	float AnguloActual;
	bool bPersonajeMontado;

	UPROPERTY()
	ACharacter* PersonajeActual; // para seguir su estado
	// Verifica si el personaje sigue montado
	void VerificarMontura();
	void Volar(float DeltaTime);
	void SubirPersonaje(ACharacter* Personaje);



	UFUNCTION()
	void OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,bool bFromSweep, const FHitResult& SweepResult);

};
