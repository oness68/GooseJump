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

	_BoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollider"));
	_BoxCollider->SetupAttachment(_SceneRoot);


	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFoothold::BeginPlay()
{
	Super::BeginPlay();
	//_BoxCollider->OnComponentBeginOverlap.AddDynamic(this, &AFoothold::BeginOverlap);
	
}

void AFoothold::SetTriggerFlag()
{
	_triggerFlag = true;
}

// Called every frame
void AFoothold::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

void AFoothold::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("OnbeginOverlap!"));
}

