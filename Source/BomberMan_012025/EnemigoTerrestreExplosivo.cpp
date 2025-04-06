// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemigoTerrestreExplosivo.h"
#include "Particles/ParticleSystemComponent.h"
#include "Components/SphereComponent.h"
#include "BomberMan_012025Character.h"
#include "BomberMan_012025GameMode.h"
#include "TimerManager.h"
#include "Kismet/KismetMathLibrary.h"
#include "Engine/Engine.h"

AEnemigoTerrestreExplosivo::AEnemigoTerrestreExplosivo()
{

	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Cone.Shape_Cone'"));
	if (MeshAsset.Succeeded())
	{
		MeshEnemigo->SetStaticMesh(MeshAsset.Object);
	}


	//para asignar Material al bloque
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> ObjetoBloqueMaterial(TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/Explosi.Explosi'"));
	if (ObjetoBloqueMaterial.Succeeded())
	{
		MeshEnemigo->SetMaterial(0, ObjetoBloqueMaterial.Object);

	}

	// particula niebla
	static ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleSystemAsset(TEXT("/Script/Engine.ParticleSystem'/Game/StarterContent/Particles/P_Explosion.P_Explosion'"));
	if (ParticleSystemAsset.Succeeded())
	{
		ParticleSystem->SetTemplate(ParticleSystemAsset.Object);

		// Escala para la particula
		ParticleSystem->SetWorldScale3D(FVector(1.0f, 1.0f, 1.5f));
	}
	// Colisión
	CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionComponent"));
	CollisionComponent->InitSphereRadius(50.0f);
	CollisionComponent->SetCollisionProfileName("Trigger");
	CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &AEnemigoTerrestreExplosivo::OnOverlapBegin);
	RootComponent = CollisionComponent;

	AjustarTamano(FVector(3.0f, 3.0f, 5.5f));
	// Inicializar variables
	VelocidadDeMovimiento = 100.f;
	Vida = 100.f;
	Danio = 10.f;
	bMovimientoPermitido = true;

	ClaseEnemigo = AEnemigoTerrestreExplosivo::StaticClass();
}

void AEnemigoTerrestreExplosivo::BeginPlay()
{
	Super::BeginPlay();
	SetActorLocation(FVector(2440.f, 4370.f, 100.f));
	if (GameModeReference && GameModeReference->PuntosPatrullaLibres.Num() > 0)
	{
		int32 Index = FMath::RandRange(0, GameModeReference->PuntosPatrullaLibres.Num() - 1);
		SetActorLocation(GameModeReference->PuntosPatrullaLibres[Index]);
		float Angulo = FMath::RandRange(0, 3) * 90.0f;
		SetActorRotation(FRotator(0, Angulo, 0));
	}
}

void AEnemigoTerrestreExplosivo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!bMovimientoPermitido || !GameModeReference) return;

	FVector Direccion = GetActorForwardVector();
	FVector NuevaPos = GetActorLocation() + Direccion * VelocidadMovimineto * DeltaTime;

	if (EsEspacioLibre(NuevaPos))
	{
		SetActorLocation(NuevaPos);
	}
	else
	{
		CambiarDireccion();
	}
}
void AEnemigoTerrestreExplosivo::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor != this && OtherActor->IsA(ABomberMan_012025Character::StaticClass()))
	{
		UE_LOG(LogTemp, Warning, TEXT(" Enemigo explosivo colisiono con el personaje y explotara."));

		// Detener movimiento y colisiones
		bMovimientoPermitido = false;
		SetActorEnableCollision(false);
		MeshEnemigo->SetVisibility(false);

		// Activar explosión visual
		if (ParticleSystem)
		{
			ParticleSystem->ActivateSystem();
		}

		// Guardar posición para reaparecer
		FVector PosicionActual = GetActorLocation();

		FTimerHandle TimerRespawn;
		GetWorld()->GetTimerManager().SetTimer(TimerRespawn, [this]() {
			if (GameModeReference)
			{
				int32 Index = FMath::RandRange(0, GameModeReference->PuntosPatrullaLibres.Num() - 1);
				FVector NuevaPos = GameModeReference->PuntosPatrullaLibres[Index];
				GetWorld()->SpawnActor<AEnemigoTerrestreExplosivo>(ClaseEnemigo, NuevaPos, FRotator::ZeroRotator);
				UE_LOG(LogTemp, Warning, TEXT("Nuevo enemigo explosivo reaparecio."));
			}
			}, 3.0f, false);
		// Destruir actor actual luego de mostrar explosión
		FTimerHandle TimerDestruir;
		GetWorld()->GetTimerManager().SetTimer(TimerDestruir, this, &AEnemigoTerrestreExplosivo::Destruir, 0.5f, false);
	}
}
void AEnemigoTerrestreExplosivo::Destruir()
{
	Destroy();
}
void AEnemigoTerrestreExplosivo::Respawn()
{
	// Elegimos una nueva posición aleatoria cercana
	FVector NuevaPos = GetActorLocation() + FVector(FMath::FRandRange(-500.0f, 500.0f),FMath::FRandRange(-500.0f, 500.0f),0.0f);

	SetActorLocation(NuevaPos);
	SetActorEnableCollision(true);
	SetActorHiddenInGame(false);

	UE_LOG(LogTemp, Warning, TEXT("Enemigo explosivo ha reaparecido."));

}

void AEnemigoTerrestreExplosivo::CambiarDireccion()
{
	float Angulo = FMath::RandRange(0, 3) * 90.0f; // 0, 90, 180, 270
	SetActorRotation(FRotator(0, Angulo, 0));
}
