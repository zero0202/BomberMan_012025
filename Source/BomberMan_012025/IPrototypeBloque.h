// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IPrototypeBloque.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UIPrototypeBloque : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class BOMBERMAN_012025_API IIPrototypeBloque
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	//virtual ~IIPrototypeBloque() = default;
	virtual AActor* Clonar(UWorld* Mundo, const FVector& Posicion) const = 0;

};
