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

	UPROPERTY(VisibleAnywhere, Category = "FoolHold|Property")
	float _onitTime=0.0f;

	UPROPERTY(VisibleAnywhere, Category = "FoolHold|Property")
	bool _triggerFlag = false;



	AFoothold();
	

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "FoolHold|Property")
	float _lifetime = 3.0f;
	// Called when the game starts or when spawned
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FootHold|Component")
	UStaticMeshComponent* _Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FootHold|Component")
	UBoxComponent* _BoxCollider;

	USceneComponent* _SceneRoot;
	virtual void BeginPlay() override;


public:	
	
	UFUNCTION()
	void SetTriggerFlag();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	


};
