// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#include "Enemy.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/TriggerVolume.h"
#include "Enemy.h"
#include "Door.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnOpenDoor, bool, Value);


UCLASS()
class NINJATEST_API ADoor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ADoor();

	UPROPERTY(EditAnywhere, Category = Enemies)
		TArray<AEnemy*> RemainingEnemies;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	virtual void Tick(float DeltaTime) override;
	void OpenDoor(float DeltaTime);
	bool CanOpen();

	UPROPERTY(BlueprintCallable, BlueprintAssignable, Category = "Dispatchers")
		FOnOpenDoor DoorOpened;

private:

	float InitialYaw;
	float CurrentYaw;
	bool IsOpen = false;


	UPROPERTY(EditAnywhere)
		float TargetYaw = 90.f;

	UPROPERTY(EditAnywhere)
		float DoorOpenSpeed = 1.f;

};
