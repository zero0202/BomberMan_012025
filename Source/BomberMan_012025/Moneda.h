// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Moneda.generated.h"

class UStaticMeshComponent;
class ABomberMan_012025GameMode;

UCLASS()
class BOMBERMAN_012025_API AMoneda : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMoneda();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	float VelocidadRotacion = 90.0f;
	float AnguloMaximoRotacion = 360.0f;

	UStaticMeshComponent* MeshMoneda;
	FVector EjeRotacion = FVector(0.f, 0.f, 1.f);
private:

	float AnguloActual = 0.f;
	bool bRotandoPositivo = true;
	FVector PosicionInicial;
	bool bVolverAPosicionInicial = false;
	int32 CiclosCompletos = 0;

	UPROPERTY()
	ABomberMan_012025GameMode* GameModeRef;

	void SaltarAPosicionAleatoria();
};
