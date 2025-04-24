// Fill out your copyright notice in the Description page of Project Settings.


#include "Teletransportador.h"
#include "Components/StaticMeshComponent.h"
#include "BomberMan_012025GameMode.h"
#include "BomberMan_012025Character.h"
#include "Engine/Engine.h"
#include "TimerManager.h"
#include "Kismet/GameplayStatics.h"


ATeletransportador::ATeletransportador() 
{
	PrimaryActorTick.bCanEverTick = true;
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	RootComponent = MeshComp;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));
	if (MeshAsset.Succeeded())
	{
		MeshComp->SetStaticMesh(MeshAsset.Object);
		MeshComp->SetRelativeScale3D(FVector(1.0f, 1.4f, 20.0f));
	}

	MeshComp->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	MeshComp->SetGenerateOverlapEvents(true);
	// Configurar colisiones
	MeshComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	MeshComp->SetCollisionObjectType(ECC_WorldDynamic);
	MeshComp->SetCollisionResponseToAllChannels(ECR_Ignore);
	MeshComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	MeshComp->SetGenerateOverlapEvents(true);

	// Vincular evento
	MeshComp->OnComponentBeginOverlap.AddDynamic(this, &ATeletransportador::OnOverlapBegin);

}

void ATeletransportador::BeginPlay()
{
	Super::BeginPlay();
	if (!bEsPuertaFija)
	{
		AlternarEstadoPuerta();
	}
	else
	{
		// Activar y dejar fija
		MeshComp->SetVisibility(true);
		MeshComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	}

}

void ATeletransportador::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void ATeletransportador::SetGameMode(ABomberMan_012025GameMode* GameMode)
{
	GameModeRef = GameMode;
}

void ATeletransportador::AlternarEstadoPuerta()
{
	if (bEsPuertaFija)
	{
		
		MeshComp->SetVisibility(true);
		MeshComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
		return; 
	}

	bEstaActiva = !bEstaActiva;

	MeshComp->SetVisibility(bEstaActiva);
	MeshComp->SetCollisionEnabled(bEstaActiva ? ECollisionEnabled::QueryOnly : ECollisionEnabled::NoCollision);

	
	int32 Tiempo = FMath::RandRange(TiempoMin, TiempoMax);

	
	GetWorld()->GetTimerManager().SetTimer(TimerAlternarEstado, this, &ATeletransportador::AlternarEstadoPuerta, Tiempo, false);

}

void ATeletransportador::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!OtherActor || OtherActor == this || !GameModeRef) return;

	if (!OtherActor->IsA(ABomberMan_012025Character::StaticClass())) return;

	float TiempoActual = GetWorld()->GetTimeSeconds();
	float* UltimoTiempo = GameModeRef->ActoresTeletransportados.Find(OtherActor);
	if (UltimoTiempo && TiempoActual - *UltimoTiempo < TiempoEsperaTeletransporte)
	{
		return;
	}

	GameModeRef->ActoresTeletransportados.Add(OtherActor, TiempoActual);

	// Elegir una puerta aleatoria diferente a esta
	TArray<ATeletransportador*> OtrasPuertas;
	for (ATeletransportador* Puerta : CompuertasConectadas)
	{
		if (Puerta && Puerta != this)
		{
			OtrasPuertas.Add(Puerta);
		}
	}

	if (OtrasPuertas.Num() == 0) return;

	int32 IndexDestino = FMath::RandRange(0, OtrasPuertas.Num() - 1);
	FVector PosicionDestino = OtrasPuertas[IndexDestino]->GetActorLocation();

	OtherActor->SetActorLocation(PosicionDestino);

	UE_LOG(LogTemp, Warning, TEXT("fue teletransportado a otra puerta"), *OtherActor->GetName());
}