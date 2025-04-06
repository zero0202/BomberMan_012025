// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemigoSubterraneoGolem.h"
#include "Components/SphereComponent.h"
#include "BomberMan_012025Character.h"
#include "BomberMan_012025GameMode.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Engine/Engine.h"

AEnemigoSubterraneoGolem::AEnemigoSubterraneoGolem()
{
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
	if (MeshAsset.Succeeded())
	{
		MeshEnemigo->SetStaticMesh(MeshAsset.Object);
	}
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> ObjetoBloqueMaterial(TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/Gold.Gold'"));
	if (ObjetoBloqueMaterial.Succeeded())
	{
		MeshEnemigo->SetMaterial(0, ObjetoBloqueMaterial.Object);
	}

	USphereComponent* ColisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("ColisionComponent"));
	ColisionComponent->InitSphereRadius(120.f);
	ColisionComponent->SetCollisionProfileName(TEXT("Trigger"));
	ColisionComponent->OnComponentBeginOverlap.AddDynamic(this, &AEnemigoSubterraneoGolem::OnCollisionWithPlayer);
	RootComponent = ColisionComponent;


	AjustarTamano(FVector(5.0f, 5.0f, 5.5f));
	VelocidadMovimineto = 80.f;
	Vida = 100;
	Danio = 20;
	bYaAparecio = false;
}

void AEnemigoSubterraneoGolem::BeginPlay()
{
	Super::BeginPlay();

	if (GameModeReference && GameModeReference->PuntosPatrullaLibres.Num() > 0)
	{
		int32 Index = FMath::RandRange(0, GameModeReference->PuntosPatrullaLibres.Num() - 1);
		FVector Pos = GameModeReference->PuntosPatrullaLibres[Index];
		Pos.Z = -500.0f; // Inicia bajo tierra
		SetActorLocation(Pos);

		float Angulo = FMath::RandRange(0, 3) * 90.0f;
		SetActorRotation(FRotator(0, Angulo, 0));
	}
}

void AEnemigoSubterraneoGolem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!bYaAparecio)
	{
		AparecerDesdeAbajo();
		return;
	}

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
void AEnemigoSubterraneoGolem::AparecerDesdeAbajo()
{
	FVector Actual = GetActorLocation();
	Actual.Z += 10.f;

	if (Actual.Z >= 100.f) // Z objetivo
	{
		Actual.Z = 100.f;
		bYaAparecio = true;
	}
	SetActorLocation(Actual);
}

void AEnemigoSubterraneoGolem::CambiarDireccion()
{
	float Angulo = FMath::RandRange(0, 3) * 90.0f;
	SetActorRotation(FRotator(0, Angulo, 0));
}

void AEnemigoSubterraneoGolem::OnCollisionWithPlayer(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ABomberMan_012025Character* Personaje = Cast<ABomberMan_012025Character>(OtherActor);
	if (Personaje)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Purple, TEXT("¡Se encontró con el enemigo GOLEM!"));

		FVector Empuje = FVector(0.f, 1000.f, 0.f);
		Personaje->LaunchCharacter(Empuje, true, false);
	}
}