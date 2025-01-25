// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"


// Sets default values
AItem::AItem()
{
    SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
    SetRootComponent(SceneRoot);

    StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
    StaticMeshComp->SetupAttachment(SceneRoot);

   
   // ''


    /*static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Resources/Props/SM_Chair.SM_Chair"));
    if (MeshAsset.Succeeded())
    {
        StaticMeshComp->SetStaticMesh(MeshAsset.Object);
    }

    static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/Resources/Materials/M_Key_B.M_Key_B"));
    {
        if (MaterialAsset.Succeeded())
        {
            StaticMeshComp->SetMaterial(0,MaterialAsset.Object);
        }
    }*/

    PrimaryActorTick.bCanEverTick = true;

    RotationSpeedYaw = 90.0f;
    SpeedZ = 200.0f;

}


void AItem::BeginPlay()
{
    Super::BeginPlay();

    //SetActorLocation(FVector(300.0f, 200.0f, 100.0f));
  //  SetActorRotation(FRotator(0.0f, 90.0f, 0.0f)); 
   // SetActorScale3D(FVector(2.0f));


    FVector NewLocation(300.0f, 200.0f, 100.0f);
    FRotator NewRotation(0.0f, 90.0f, 0.0f);
    FVector NewScale(1.0f);

    FTransform NewTransForm(NewRotation, NewLocation, NewScale);

   
    SetActorTransform(NewTransForm);

    OnItemPickUp();

    Times = 0.0f;
    DefaultPos = this->GetActorLocation();
    AddScale = 2.0f;

   

}

void AItem::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    Times += DeltaTime;
    
    if (Times > 2.0f)
    {  
        flag = !flag;
        Times = 0.0f;
    }

    if (flag)
    {
        SetActorScale3D(this->GetActorScale3D() + FVector(AddScale * DeltaTime));
    }
    else
    {
        SetActorScale3D(this->GetActorScale3D() +FVector(-AddScale * DeltaTime));
    }


    if (!FMath::IsNearlyZero(RotationSpeedYaw))
    {
        AddActorLocalRotation(FRotator(0.0f, RotationSpeedYaw * DeltaTime, 0.0f));

    }

    if (_Distance > 100.0f)
    {
        SpeedZ = SpeedZ*-1;
    }

    AddActorWorldOffset(FVector(0.0f, 0.0f, SpeedZ * DeltaTime));
    
    _Distance = FVector::Distance(DefaultPos, this->GetActorLocation());

}

void AItem::ResetActorPosition()
{
    SetActorLocation(FVector::ZeroVector);
}

float AItem::GetRotationSpeedYaw() const
{
    return RotationSpeedYaw;
}





