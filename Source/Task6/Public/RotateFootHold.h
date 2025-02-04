// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotateFootHold.generated.h"

UCLASS()
class TASK6_API ARotateFootHold : public AActor
{
	GENERATED_BODY()
	
private:
	FRotator MeshDefaultRotation;


public:	
	// Sets default values for this actor's properties
	ARotateFootHold();

	
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* _StaticMesh;


	USceneComponent* _SceneRoot;

public:	


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FootHold | Property")
	float RotationX = 0.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FootHold | Property")
	float RotationY = 0.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FootHold | Property")
	float RotationZ = 0.0f;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
