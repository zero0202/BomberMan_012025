// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemigoAereo.h"
#include "EnemigoAereoTransportador.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN_012025_API AEnemigoAereoTransportador : public AEnemigoAereo
{
	GENERATED_BODY()
	
	public:
	AEnemigoAereoTransportador();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	// Ruta circular
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movimiento")
	float Radio = 10000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movimiento")
	float AlturaFlotante = 300.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movimiento")
	float VelocidadAngular = 20.0f; // grados por segundo

	UPROPERTY()
	bool bPersonajeMontado;

	UPROPERTY()
	ACharacter* PersonajeActual; // para seguir su estado

	// Verifica si el personaje sigue montado
	void VerificarMontura();
private:
	float AnguloActual;


	//UFUNCTION()
	//void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,bool bFromSweep, const FHitResult& SweepResult);
};
