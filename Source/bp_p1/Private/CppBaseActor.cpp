// Fill out your copyright notice in the Description page of Project Settings.

#include "CppBaseActor.h"
#include "Engine/Engine.h"
#include "Math/UnrealMathUtility.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ACppBaseActor::ACppBaseActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);
}

// Called when the game starts or when spawned
void ACppBaseActor::BeginPlay()
{
	Super::BeginPlay();
	ACppBaseActor::CurrentLocation = FVector(50.0f, 50.0f, 0.0f);
	ACppBaseActor::EnemyNum = rand() % 10;
	ACppBaseActor::IsAlive = static_cast<bool>(rand() % 2);
	ShowActorInformation();
	++ACppBaseActor::InstanceID;
}

// Called every frame
void ACppBaseActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACppBaseActor::ShowActorInformation()
{
	UE_LOG(LogTemp, Display, TEXT("Instance name: A_CppBase_C_%d"), ACppBaseActor::InstanceID);
	UE_LOG(LogTemp, Display, TEXT("EnemyNum: %d"), ACppBaseActor::EnemyNum);
	UE_LOG(LogTemp, Display, TEXT("IsAlive: %i"), ACppBaseActor::IsAlive);
}

void ACppBaseActor::SinMovement()
{
	float time = GetWorld()->GetTimeSeconds();
	float newZ = ACppBaseActor::Amplitude * FMath::Sin(ACppBaseActor::Frequency * time);
	ACppBaseActor::CurrentLocation.Z = newZ;
	SetActorLocation(ACppBaseActor::CurrentLocation);
}
