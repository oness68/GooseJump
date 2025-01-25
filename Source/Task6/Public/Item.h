// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"



UCLASS()
class TASK6_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item|Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Components")
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Item|Components")
	float RotationSpeedYaw;
	float SpeedZ;
	float Times;
	UPROPERTY(VisibleAnywhere)
	bool flag=true;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	FVector3d TargetPos;
	FVector3d DefaultPos;
	float AddScale;

	UPROPERTY(VisibleAnywhere)
	float _Distance=0;
	//UMaterial*

	UFUNCTION(BlueprintCallable, Category = "Item|Action")
	void ResetActorPosition();


	UFUNCTION(BlueprintPure, Category = "Item|Properties")
	float GetRotationSpeedYaw() const;

public:

	UFUNCTION(BlueprintImplementableEvent, Category = "Item|Event")
	void OnItemPickUp();
};
