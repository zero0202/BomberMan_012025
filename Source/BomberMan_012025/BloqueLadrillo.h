// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BloqueLadrillo.generated.h"

class UStaticMeshComponent;
class UMaterialInterface;

UCLASS()
class BOMBERMAN_012025_API ABloqueLadrillo : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABloqueLadrillo();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* MeshBloqueLadrillo;

	UPROPERTY(VisibleAnywhere)
	UMaterialInterface* BloqueLadrilloMaterial;

	UFUNCTION(BlueprintCallable)
	void AjustarTamanoAcero(FVector NuevoTamano);
	
	float velocidad;
	float amplitud;

private:
	// Posici�n inicial del objeto en el eje Z
	float PosicionInicial;

};
