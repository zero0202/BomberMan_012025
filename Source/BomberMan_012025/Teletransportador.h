// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Teletransportador.generated.h"
class ABomberMan_012025GameMode;

UCLASS()
class BOMBERMAN_012025_API ATeletransportador : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATeletransportador();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// Componente visual
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* MeshComp;

	// Compuerta de destino
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Teletransporte")
	ATeletransportador* CompuertaDestino;

	// Referencia al GameMode
	UPROPERTY()
	ABomberMan_012025GameMode* GameModeRef;

	// Tiempo mínimo entre teletransportes del mismo actor
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Teletransporte")
	float TiempoEsperaTeletransporte = 2.0f;

	// Evento de colisión
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	// Establecer referencia del GameMode
	void SetGameMode(ABomberMan_012025GameMode* GameMode);
};
