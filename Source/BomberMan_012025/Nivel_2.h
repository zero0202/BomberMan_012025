// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ConfiguracionNivel.h"
#include "Nivel_2.generated.h"

UCLASS()
class BOMBERMAN_012025_API ANivel_2 : public AActor, public IConfiguracionNivel
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANivel_2();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	virtual void GenerarEnemigosNivel() override;
	virtual void EnemigoVida() override;
	virtual void Monedas() override;

private:

	float EVida;


};
