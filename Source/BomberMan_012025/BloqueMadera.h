// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BloqueMadera.generated.h"

class UStaticMeshComponent;
class UMaterialInterface;

UCLASS()
class BOMBERMAN_012025_API ABloqueMadera : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABloqueMadera();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
public:

	UPROPERTY()
	UStaticMeshComponent* MeshBloqueMadera; 
	UPROPERTY()
	UMaterialInterface* BloqueMaderaMaterial;

	bool bAbriendo;
	float VelocidadMovimiento;
	float DistanciaApertura; // Distancia m�xima al abrir
	FVector PosicionInicial; // Posici�n inicial


	UFUNCTION(BlueprintCallable)
	void AjustarTamanoAcero(FVector NuevoTamano);
};
