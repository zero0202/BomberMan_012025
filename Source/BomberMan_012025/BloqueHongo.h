// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Bloque.h"
#include "BloqueHongo.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN_012025_API ABloqueHongo : public ABloque
{
	GENERATED_BODY()
	
public:
		ABloqueHongo();
protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	
};
