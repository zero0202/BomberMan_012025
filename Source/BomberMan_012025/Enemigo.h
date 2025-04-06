// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BomberMan_012025Character.h"
#include "Enemigo.generated.h"

class UStaticMeshComponent;
class UParticleSystemComponent;
class ABomberMan_012025GameMode;
/**
 * 
 */
UCLASS()
class BOMBERMAN_012025_API AEnemigo : public ABomberMan_012025Character
{
	GENERATED_BODY()
	
public:

	AEnemigo();

protected:

	virtual void BeginPlay() override;

public:

	virtual void Tick(float DeltaTime) override;

protected:


	float Altura;
	float Danio;
	float VelocidadMovimineto;
	int Vida;

protected:

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* MeshEnemigo;

	UPROPERTY(VisibleAnywhere)
	UParticleSystemComponent* ParticleSystem;
	ABomberMan_012025GameMode* GameModeReference; // Referencia al modo de juego
	float Espaciado = 900.0f;
	bool EsEspacioLibre(FVector Pos);
public:

	virtual void AjustarTamano(FVector NuevoTamano);
	virtual void RecibirDanio(float Danio);
	virtual void Morir();	
	virtual void MoverEnemigo(float DeltaTime);
};
