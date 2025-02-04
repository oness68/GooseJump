// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <Components/BoxComponent.h>
#include "GameFramework/Actor.h"
#include "Foothold.generated.h"

UCLASS()
class TASK6_API AFoothold : public AActor
{
	GENERATED_BODY()
	
private:

	AFoothold();
	FVector DefalutPos;

protected:
	
	// Called when the game starts or when spawned
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FootHold|Component")
	UStaticMeshComponent* _Mesh;


	USceneComponent* _SceneRoot;
	virtual void BeginPlay() override;


public:	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FoolHold|Property")
	float Distance = 100.0f;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "FoolHold|Property")
	float CurrentDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FoolHold|Property")
	float speedZ = 10.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FoolHold|Property")
	float speedX = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FoolHold|Property")
	float speedY = 0.0f;;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	


};
