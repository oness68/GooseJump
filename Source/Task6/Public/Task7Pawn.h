// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Task7Pawn.generated.h"


class USpringArmComponent;
class UCameraComponent;
struct FInputActionValue;
class UCapsuleComponent;

UCLASS()
class TASK6_API ATask7Pawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATask7Pawn();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	USpringArmComponent* SpringArmComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	UCameraComponent* CameraComp;
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
	UCapsuleComponent* CapsuleComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* StaticMesh;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MoveProperty")
	float Speed;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "MoveProperty")
	float JumpPower=300.0f;

	UFUNCTION()
	void Move(const FInputActionValue& value);
	UFUNCTION()
	void StopMove();
	UFUNCTION()
	void MoveForward(float DeltaTime);
	UFUNCTION()
	void Look(const FInputActionValue& value);

	UFUNCTION()
	void StopLook();

	UFUNCTION()
	void LookAt(float DeltaTime);

	FVector2D MoveInput;
	FVector2D LookInput;
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
