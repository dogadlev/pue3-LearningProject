// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CppBaseActor.generated.h"

class UStaticMeshComponent;

USTRUCT(BlueprintType)
struct FTransformStruct
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector CurrentLocation = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FRotator CurrentRotation = FRotator::ZeroRotator;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector CurrentScale = FVector(1.0f, 1.0f, 1.0f);
};

UENUM(BlueprintType)
enum class EmovementState : uint8
{
	Mobility,
	Static
};

UCLASS()
class BP_P1_API ACppBaseActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACppBaseActor();

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	static inline unsigned InstanceID{};

	UPROPERTY(EditAnywhere);
	int EnemyNum{};

	UPROPERTY(EditAnywhere);
	bool IsAlive = true;

	UPROPERTY(EditInstanceOnly)
	float Amplitude = 40.0f;

	UPROPERTY(EditInstanceOnly)
	float Frequency = 5.0f;

	UPROPERTY(BlueprintReadWrite)
	FVector CurrentLocation;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UFUNCTION(BlueprintCallable)
	void ShowActorInformation();

	UFUNCTION(BlueprintCallable)
	void SinMovement();
};
