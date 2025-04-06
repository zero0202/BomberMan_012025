// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemigoTerrestreTortuga.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Character.h"
#include "BomberMan_012025Character.h"
#include "BomberMan_012025GameMode.h"
#include "Engine/Engine.h"

AEnemigoTerrestreTortuga::AEnemigoTerrestreTortuga()
{
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	if (MeshAsset.Succeeded())
	{
		MeshEnemigo->SetStaticMesh(MeshAsset.Object);
	}
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> ObjetoBloqueMaterial(TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/EfectoF.EfectoF'"));
	if (ObjetoBloqueMaterial.Succeeded())
	{
		MeshEnemigo->SetMaterial(0, ObjetoBloqueMaterial.Object);
	}

	// Configurar colision
	USphereComponent* ColisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("ColisionComponent"));
	ColisionComponent->InitSphereRadius(100.f);
	ColisionComponent->SetCollisionProfileName(TEXT("Trigger"));
	ColisionComponent->OnComponentBeginOverlap.AddDynamic(this, &AEnemigoTerrestreTortuga::OnCollisionWithPlayer);
	RootComponent = ColisionComponent;

	AjustarTamano(FVector(3.0f, 3.0f, 4.5f));
	
	VelocidadMovimineto = 100.f;
	Vida = 100;
	Danio = 20;
	DefensaCaparazon = 30.f;
	bEnCaparazon = false;
}

void AEnemigoTerrestreTortuga::BeginPlay()
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

void AEnemigoTerrestreTortuga::Tick(float DeltaTime)
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

void AEnemigoTerrestreTortuga::OnCollisionWithPlayer(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ABomberMan_012025Character* Personaje = Cast<ABomberMan_012025Character>(OtherActor);
	if (Personaje)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("La tortuga colisionó con el jugador!"));
		ActivarCaparazon();
	}
}

void AEnemigoTerrestreTortuga::ActivarCaparazon()
{
	bEnCaparazon = true;
	FTimerHandle TimerHandle;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, [this]() {
		bEnCaparazon = false;
		}, 3.0f, false);
}

void AEnemigoTerrestreTortuga::CambiarDireccion()
{
	FRotator NuevaRot = GetActorRotation();
	NuevaRot.Yaw += 90.0f;
	SetActorRotation(NuevaRot);
}
