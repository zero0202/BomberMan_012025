// Fill out your copyright notice in the Description page of Project Settings.


#include "ContenedorMonedas.h"
#include "Moneda.h"
#include "Engine/Engine.h"

// Sets default values
AContenedorMonedas::AContenedorMonedas()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Elementos = nullptr;
}

// Called when the game starts or when spawned
void AContenedorMonedas::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AContenedorMonedas::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AContenedorMonedas::AgregarElemento(IIElementoInventario* Elementos)
{
	if (Elementos) 
	{
		Elemento.Add(Elementos);

	}
}

void AContenedorMonedas::RemoverElemento(IIElementoInventario* Elementos)
{
	Elemento.Remove(Elementos);
}

void AContenedorMonedas::MostrarContenedor()
{

	for (auto& Elementos: Elemento)
	{
		if (Elementos)
		{
			Elementos->MostrarContenedor();
		}
	}
}

