// Fill out your copyright notice in the Description page of Project Settings.


#include "BloqueConcreto.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInterface.h"
#include "Engine/World.h"
#include "BomberMan_012025Character.h"

// Sets default values
ABloqueConcreto::ABloqueConcreto()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshBloqueConcreto = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshBloqueConcreto"));
	RootComponent = MeshBloqueConcreto;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshBloqueConcretoAsset(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Cone.Shape_Cone'"));
	if (MeshBloqueConcretoAsset.Succeeded())
	{
		MeshBloqueConcreto->SetStaticMesh(MeshBloqueConcretoAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterialInterface> BloqueConcretoMaterialAsset(TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/M_Ground_Grass.M_Ground_Grass'"));
	if (BloqueConcretoMaterialAsset.Succeeded())
	{
		MeshBloqueConcreto->SetMaterial(0, BloqueConcretoMaterialAsset.Object);
	}

	AjustarTamanoConcreto(FVector(2.0f, 2.0f, 2.0f));

	// Configurar la colisión
	MeshBloqueConcreto->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	MeshBloqueConcreto->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	MeshBloqueConcreto->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap); // Asegúrate de que colisione con el personaje

	
}

// Called when the game starts or when spawned
void ABloqueConcreto::BeginPlay()
{
	Super::BeginPlay();

	//MeshBloqueConcreto->OnComponentBeginOverlap.AddDynamic(this, &ABloqueConcreto::OnOverlapBegin);
}

// Called every frame
void ABloqueConcreto::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}
void ABloqueConcreto::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	// Verificar si el actor que colisiona es tu personaje
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		// Aquí puedes verificar si OtherActor es de la clase de tu personaje
		ABomberMan_012025Character* Character = Cast<ABomberMan_012025Character>(OtherActor);
		if (Character)
		{
			// Destruir el bloque
			Destroy();
		}
	}
}

void ABloqueConcreto::AjustarTamanoConcreto(FVector NuevoTamano)
{
	MeshBloqueConcreto->SetWorldScale3D(NuevoTamano);
}
