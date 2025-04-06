// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemigoAereoTransportador.h"
#include "Components/StaticMeshComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "Components/SphereComponent.h"
#include "Materials/MaterialInterface.h"

AEnemigoAereoTransportador::AEnemigoAereoTransportador()
{

	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Cylinder.Shape_Cylinder'"));
	if (MeshAsset.Succeeded())
	{
		MeshEnemigo->SetStaticMesh(MeshAsset.Object);
	}


	//para asignar Material al bloque
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> ObjetoBloqueMaterial(TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/M_Tech_Panel.M_Tech_Panel'"));
	if (ObjetoBloqueMaterial.Succeeded())
	{
		MeshEnemigo->SetMaterial(0, ObjetoBloqueMaterial.Object);

	}

	// particula niebla
	static ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleSystemAsset(TEXT("/Game/StarterContent/Particles/P_Steam_Lit.P_Steam_Lit"));
	if (ParticleSystemAsset.Succeeded())
	{
		ParticleSystem->SetTemplate(ParticleSystemAsset.Object);

		// Escala para la particula
		ParticleSystem->SetWorldScale3D(FVector(10.0f, 10.0f, 10.5f));
	}

	GetCharacterMovement()->GravityScale = 0.0f;
	AjustarTamano(FVector(4.0f, 4.0f, 0.5f));

	VelocidadVuelo = 400.0f;
	AlturaFlotante = 650.0f;
	AlturaVuelo = 800.0f;
	Radio = 13000.0f;
	VelocidadAngular = 2.0f;
	AnguloActual = 7000.0f;
	bPersonajeMontado = false;

	// Inicializar el collider para verificar las colisiones
	USphereComponent* ColliderComponent = CreateDefaultSubobject<USphereComponent>(TEXT("ColliderComponent"));
	ColliderComponent->SetupAttachment(RootComponent);
	ColliderComponent->InitSphereRadius(200.0f);  // Ajustar el tamaño de la esfera para detectar el personaje
	ColliderComponent->SetCollisionProfileName(TEXT("Trigger"));  // Configura como Trigger para colisiones
	ColliderComponent->OnComponentBeginOverlap.AddDynamic(this, &AEnemigoAereoTransportador::OnComponentBeginOverlap);

}

void AEnemigoAereoTransportador::BeginPlay()
{
	Super::BeginPlay();


}

void AEnemigoAereoTransportador::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Movimiento en círculo
	AnguloActual += VelocidadAngular * DeltaTime;
	if (AnguloActual >= 360.f) AnguloActual -= 360.f;

	float Radians = FMath::DegreesToRadians(AnguloActual);
	FVector Centro = FVector(20000.0f, 8450.0f, AlturaFlotante); // centro del laberinto
	FVector NPosicion = Centro + FVector(FMath::Cos(Radians) * Radio, FMath::Sin(Radians) * Radio, AlturaFlotante);

	SetActorLocation(NPosicion);

	// Si el personaje está montado, moverlo junto con el enemigo
	if (bPersonajeMontado && PersonajeActual)
	{
		Volar(DeltaTime);
	}
	VerificarMontura();
}
void AEnemigoAereoTransportador::Volar(float DeltaTime)
{
	// Mueve suavemente el actor a la AlturaVuelo definida
	FVector PosicionActual = GetActorLocation();
	PosicionActual.Z = AlturaVuelo;

	// Aumentar la altura del enemigo cuando el personaje está montado
	if (bPersonajeMontado)
	{
		PosicionActual.Z += 500.0f;  // Sube aún más cuando el personaje está montado
	}

	FVector NuevaPosicion = FMath::VInterpTo(GetActorLocation(), PosicionActual, DeltaTime, 1.0f);
	SetActorLocation(NuevaPosicion);
}
void AEnemigoAereoTransportador::VerificarMontura()
{
	if (!bPersonajeMontado || !PersonajeActual) return;

	// Si la distancia del personaje al enemigo es muy grande, se soltó
	float Distancia = FVector::Dist(PersonajeActual->GetActorLocation(), GetActorLocation());

	if (Distancia > 20.f) // Puedes ajustar el umbral
	{
		// Liberar personaje
		PersonajeActual->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
		bPersonajeMontado = false;
		PersonajeActual = nullptr;
	}
}
void AEnemigoAereoTransportador::OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Verifica si el actor con el que colisionamos es el personaje
	ABomberMan_012025Character* Personaje = Cast<ABomberMan_012025Character>(OtherActor);
	if (Personaje && !bPersonajeMontado)
	{
		SubirPersonaje(Personaje);
	}
}
void AEnemigoAereoTransportador::SubirPersonaje(ACharacter* Personaje)
{
	PersonajeActual = Personaje;
	bPersonajeMontado = true;

	// Mover el personaje a la posición del enemigo y mantenerlo en la misma altura de vuelo
	//PersonajeActual->SetActorLocation(GetActorLocation() + FVector(0, 0, AlturaVuelo));

	//PersonajeActual->AttachToActor(this, FAttachmentTransformRules::KeepWorldTransform);
}