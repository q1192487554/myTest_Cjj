// Fill out your copyright notice in the Description page of Project Settings.


#include "FloatingActor.h"

// Sets default values
AFloatingActor::AFloatingActor()
{
    // ����Actor��Ϊ��֡����Tick()��������˹��ܣ��ɹر���������ܡ�
    PrimaryActorTick.bCanEverTick = true;

    VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
    VisualMesh->SetupAttachment(RootComponent);

    static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));

    if (CubeVisualAsset.Succeeded())
    {
        VisualMesh->SetStaticMesh(CubeVisualAsset.Object);
        VisualMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
    }

}

// ��Ϸ��ʼʱ������ʱ����
void AFloatingActor::BeginPlay()
{
    Super::BeginPlay();

}

// ��֡����
void AFloatingActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    FVector NewLocation = GetActorLocation();
    FRotator NewRotation = GetActorRotation();
    float RunningTime = GetGameTimeSinceCreation();
    float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
    NewLocation.Z += DeltaHeight * 20.0f;       //Scale our height by a factor of 20
    float DeltaRotation = DeltaTime * 20.0f;    //Rotate by 20 degrees per second
    NewRotation.Yaw += DeltaRotation;
    SetActorLocationAndRotation(NewLocation, NewRotation);
}

