// Fill out your copyright notice in the Description page of Project Settings.


#include "BloquePegajoso.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"  
#include "Engine/Engine.h"


ABloquePegajoso::ABloquePegajoso()
{
	PrimaryActorTick.bCanEverTick = true;


	static ConstructorHelpers::FObjectFinder<UStaticMesh> ObjetoMeshBloqueAcero(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	if (ObjetoMeshBloqueAcero.Succeeded())
	{
		MeshBloque->SetStaticMesh(ObjetoMeshBloqueAcero.Object);

		MeshBloque->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	}
	//para asignar textura
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> ObjetoBloqueAceroMaterial(TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/M_Glass.M_Glass'"));
	if (ObjetoBloqueAceroMaterial.Succeeded()) 
	{
		MeshBloque->SetMaterial(0, ObjetoBloqueAceroMaterial.Object);

	}

	// Configurar la colisión
	MeshBloque->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	MeshBloque->OnComponentBeginOverlap.AddDynamic(this, &ABloquePegajoso::OnOverlapBegin);  // Detectar cuando empieza la colisión

}

void ABloquePegajoso::BeginPlay()
{
	Super::BeginPlay();

}

void ABloquePegajoso::Tick(float DeltaTime)
{

	Super::Tick(DeltaTime);
}

void ABloquePegajoso::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Verificar si el actor que colisiona es el personaje
	ACharacter* Personaje = Cast<ACharacter>(OtherActor);
	if (Personaje)
	{
		// Mostrar un mensaje en el log
		UE_LOG(LogTemp, Warning, TEXT("Personaje pegado al bloque pegajoso"));

		// Desactivar el movimiento del personaje (esto lo "pega" al bloque)
		Personaje->GetCharacterMovement()->DisableMovement();

		// Usar un temporizador para liberar al personaje después de 3 segundos
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ABloquePegajoso::LiberarPersonaje, 3.0f, false);
	}
}

void ABloquePegajoso::LiberarPersonaje()
{
	// Obtener el personaje (si está pegado)
	ACharacter* Personaje = Cast<ACharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	if (Personaje)
	{
		// Volver a activar el movimiento del personaje
		Personaje->GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_Walking);
		UE_LOG(LogTemp, Warning, TEXT("Personaje liberado del bloque pegajoso"));
	}
}
