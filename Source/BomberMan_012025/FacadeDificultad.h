// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FacadeDificultad.generated.h"

UCLASS()
class BOMBERMAN_012025_API AFacadeDificultad : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFacadeDificultad();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
public:

	class ANivel_1* Nivel1;
	class ANivel_2* Nivel2;
	class ANivel_3* Nivel3;

public:
	void IniciarNivel1();
	void IniciarNivel2();
	void IniciarNivel3();
};
