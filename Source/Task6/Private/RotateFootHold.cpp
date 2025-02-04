// Fill out your copyright notice in the Description page of Project Settings.


#include "RotateFootHold.h"

// Sets default values
ARotateFootHold::ARotateFootHold()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	_SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	SetRootComponent(_SceneRoot);


	_StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));


	_StaticMesh->SetupAttachment(_SceneRoot);

	MeshDefaultRotation = _StaticMesh->GetComponentRotation();



}

// Called when the game starts or when spawned
void ARotateFootHold::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARotateFootHold::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalRotation(FRotator(RotationY * DeltaTime, RotationZ * DeltaTime, RotationX * DeltaTime));

	_StaticMesh->SetWorldRotation(MeshDefaultRotation);

}

