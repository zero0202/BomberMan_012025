// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Bloque.h"
#include "BloquePegajoso.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN_012025_API ABloquePegajoso : public ABloque
{
	GENERATED_BODY()
	
public:
	ABloquePegajoso();
protected:	
	virtual void BeginPlay() override;
	
public:
	virtual void Tick(float DeltaTime) override;

public:

};
