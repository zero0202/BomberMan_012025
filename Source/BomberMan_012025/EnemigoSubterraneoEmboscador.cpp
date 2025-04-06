// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemigoSubterraneoEmboscador.h"
#include "Components/SphereComponent.h"
#include "BomberMan_012025Character.h"
#include "BomberMan_012025GameMode.h"
#include "Engine/Engine.h"

AEnemigoSubterraneoEmboscador::AEnemigoSubterraneoEmboscador()
{
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Tube.Shape_Tube'"));
	if (MeshAsset.Succeeded())
	{
		MeshEnemigo->SetStaticMesh(MeshAsset.Object);
	}
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> ObjetoBloqueMaterial(TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/Emboscado.Emboscado'"));
	if (ObjetoBloqueMaterial.Succeeded())
	{
		MeshEnemigo->SetMaterial(0, ObjetoBloqueMaterial.Object);
	}


	// Configurar colisión
	USphereComponent* ColisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("ColisionComponent"));
	ColisionComponent->InitSphereRadius(80.f);
	ColisionComponent->SetCollisionProfileName(TEXT("Trigger"));
	ColisionComponent->OnComponentBeginOverlap.AddDynamic(this, &AEnemigoSubterraneoEmboscador::OnCollisionWithPlayer);
	RootComponent = ColisionComponent;


	AjustarTamano(FVector(6.0f, 6.0f, 5.5f));

	VelocidadMovimineto = 400.f;

}

void AEnemigoSubterraneoEmboscador::BeginPlay()
{
	Super::BeginPlay();

	if (GameModeReference && GameModeReference->PuntosPatrullaLibres.Num() > 0)
	{
		int32 Index = FMath::RandRange(0, GameModeReference->PuntosPatrullaLibres.Num() - 1);
		SetActorLocation(GameModeReference->PuntosPatrullaLibres[Index]);

		float Angulo = FMath::RandRange(0, 3) * 90.0f;
		SetActorRotation(FRotator(0, Angulo, 0));
	}
}

void AEnemigoSubterraneoEmboscador::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector Direccion = GetActorForwardVector();
	FVector NuevaPos = GetActorLocation() + Direccion * VelocidadMovimineto * DeltaTime;

	if (GameModeReference && EsEspacioLibre(NuevaPos))
	{
		SetActorLocation(NuevaPos);
	}
	else
	{
		CambiarDireccion();
	}
}

void AEnemigoSubterraneoEmboscador::OnCollisionWithPlayer(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ABomberMan_012025Character* Personaje = Cast<ABomberMan_012025Character>(OtherActor);
	if (Personaje)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow,TEXT("¡El personaje fue emboscado por el enemigo Subterráneo!"));
	}
}

void AEnemigoSubterraneoEmboscador::CambiarDireccion()
{
	float Angulo = FMath::RandRange(0, 3) * 90.0f;
	SetActorRotation(FRotator(0, Angulo, 0));
}
