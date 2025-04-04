// Fill out your copyright notice in the Description page of Project Settings.


#include "Teletransportador.h"
#include "Components/StaticMeshComponent.h"
#include "BomberMan_012025GameMode.h"
#include "BomberMan_012025Character.h"
#include "Engine/Engine.h"
#include "TimerManager.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ATeletransportador::ATeletransportador()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	RootComponent = MeshComp;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));
	if (MeshAsset.Succeeded())
	{
		MeshComp->SetStaticMesh(MeshAsset.Object);
		MeshComp->SetRelativeScale3D(FVector(1.0f, 1.4f, 8.0f)); // Aquí cambias el tamaño visual del cubo
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

// Called when the game starts or when spawned
void ATeletransportador::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATeletransportador::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void ATeletransportador::SetGameMode(ABomberMan_012025GameMode* GameMode)
{
	GameModeRef = GameMode;
}
void ATeletransportador::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!OtherActor || OtherActor == this || !CompuertaDestino || !GameModeRef) return;

	// Verificar tipo de actor
	if (!OtherActor->IsA(ABomberMan_012025Character::StaticClass())) return;

	// Verificar cooldown individual por actor
	float TiempoActual = GetWorld()->GetTimeSeconds();
	float* UltimoTiempo = GameModeRef->ActoresTeletransportados.Find(OtherActor);
	if (UltimoTiempo && TiempoActual - *UltimoTiempo < TiempoEsperaTeletransporte)
	{
		return; // Aún en cooldown
	}

	// Actualizar tiempo
	GameModeRef->ActoresTeletransportados.Add(OtherActor, TiempoActual);

	// Teletransportar al destino
	OtherActor->SetActorLocation(CompuertaDestino->GetActorLocation());

	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, FString::Printf(TEXT(" fue teletransportado."), *OtherActor->GetName()));
}