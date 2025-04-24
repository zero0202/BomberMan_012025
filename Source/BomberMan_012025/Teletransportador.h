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

	ATeletransportador();

protected:

	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

public:

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* MeshComp;

	UPROPERTY(EditAnywhere)
	TArray<ATeletransportador*> CompuertasConectadas;

	UPROPERTY()
	ABomberMan_012025GameMode* GameModeRef;

	float TiempoEsperaTeletransporte = 2.0f;

	FTimerHandle TimerAlternarEstado;
	bool bEstaActiva = true;
	bool bEsPuertaFija = false;

	int32 TiempoMin = 1;
	int32 TiempoMax = 10;
	
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	void SetGameMode(ABomberMan_012025GameMode* GameMode);
	void AlternarEstadoPuerta();
};
