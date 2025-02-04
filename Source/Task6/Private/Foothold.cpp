// Fill out your copyright notice in the Description page of Project Settings.


#include "Foothold.h"

// Sets default values
AFoothold::AFoothold()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	_SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(_SceneRoot);

	_Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	_Mesh->SetupAttachment(_SceneRoot);
	

	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFoothold::BeginPlay()
{
	Super::BeginPlay();

	DefalutPos = this->GetActorLocation();
	//_BoxCollider->OnComponentBeginOverlap.AddDynamic(this, &AFoothold::BeginOverlap);
	
}


// Called every frame
void AFoothold::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (CurrentDistance > Distance)
	{
		DefalutPos = this->GetActorLocation();
		speedX *= -1;
		speedY *= -1;
		speedZ *= -1;

	}


	AddActorWorldOffset(FVector(speedX * DeltaTime, speedY * DeltaTime, speedZ * DeltaTime));


	CurrentDistance = FVector::Distance(DefalutPos, this->GetActorLocation());

}



