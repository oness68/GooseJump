// Fill out your copyright notice in the Description page of Project Settings.


#include "Task7Pawn.h"
#include "Components/CapsuleComponent.h"
#include "Camera/CameraComponent.h"
#include "SpartaPlayerController.h"
#include "EnhancedInputComponent.h"
#include"GameFramework/SpringArmComponent.h"
#include"GameFramework/PawnMovementComponent.h"
// Sets default values
ATask7Pawn::ATask7Pawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleCollision"));
	SetRootComponent(CapsuleComp);

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(CapsuleComp);

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArmComp->SetupAttachment(CapsuleComp);
	SpringArmComp->bUsePawnControlRotation = true; //컨트롤러 회전 적용

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComp->SetupAttachment(SpringArmComp, USpringArmComponent::SocketName);
	CameraComp->bUsePawnControlRotation = false;

	this->bUseControllerRotationYaw = true;
	Speed = 700.0f;


	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATask7Pawn::BeginPlay()
{
	Super::BeginPlay();

	
}

// Called every frame
void ATask7Pawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MoveForward(DeltaTime);
	LookAt(DeltaTime);

}
void ATask7Pawn::MoveForward(float DeltaTime)
{

	
	FVector ForwardVec = CameraComp->GetForwardVector();
	FVector RightVec = CameraComp->GetRightVector();

	FVector Direction = (FVector(ForwardVec.X, ForwardVec.Y,0.0f)*MoveInput.X)+(FVector(RightVec.X, RightVec.Y, 0.0f) * MoveInput.Y);
	

	Direction.Normalize();
	Direction = Direction * Speed * DeltaTime;

	this->AddActorLocalOffset(Direction);

	

}


// Called to bind functionality to input
void ATask7Pawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);


	if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		if (ASpartaPlayerController* PlayerController = Cast<ASpartaPlayerController>(GetController()))
		{
			if (PlayerController->MoveAction)
			{
				EnhancedInput->BindAction(PlayerController->MoveAction, ETriggerEvent::Triggered, this, &ATask7Pawn::Move);
				EnhancedInput->BindAction(PlayerController->MoveAction, ETriggerEvent::Completed, this, &ATask7Pawn::StopMove);
			
			}
			if (PlayerController->LookAction)
			{
				EnhancedInput->BindAction(PlayerController->LookAction, ETriggerEvent::Triggered, this, &ATask7Pawn::Look);
				EnhancedInput->BindAction(PlayerController->LookAction, ETriggerEvent::Completed, this, &ATask7Pawn::StopLook);
			}

		}
	}


}


void ATask7Pawn::Move(const FInputActionValue& value)
{

	MoveInput = value.Get<FVector2D>();



	
}

void ATask7Pawn::StopMove()
{
	MoveInput = FVector2D::ZeroVector;

}


void ATask7Pawn::Look(const FInputActionValue& value)
{
	LookInput = value.Get<FVector2D>();


}

void ATask7Pawn::StopLook()
{
	LookInput = FVector2D::ZeroVector;
}

void ATask7Pawn::LookAt(float DeltaTime)
{
	FRotator rotation = Controller->GetControlRotation();
	rotation.Pitch += LookInput.Y;
	rotation.Yaw += LookInput.X;

	Controller->SetControlRotation(rotation);
}

