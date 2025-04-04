// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Bloque.h"
#include "BloqueArena.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN_012025_API ABloqueArena : public ABloque
{
	GENERATED_BODY()
	
public:
	ABloqueArena();
protected:
	virtual void BeginPlay() override;
public:

	virtual void Tick(float DeltaTime) override;
	
public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UParticleSystemComponent* ParticulasArena;
	// Tiempo de la animación de hundimiento
	float TiempoArena;

	// Tiempo para hundirse completamente
	float TiempoHundimiento;

	// Almacena la posición inicial del bloque
	FVector PosicionInicial;

	// Para controlar si el bloque está hundido o no
	bool bEstaHundido;

	// Función para detectar la colisión con el personaje
	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor,class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
