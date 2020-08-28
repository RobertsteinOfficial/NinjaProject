// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"

// Sets default values
ADoor::ADoor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();

	/*InitialYaw = GetOwner()->GetActorRotation().Yaw;
	CurrentYaw = InitialYaw;
	TargetYaw += InitialYaw;*/

}

// Called every frame
void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (CanOpen())
	{
		if (!IsOpen)
		{
			DoorOpened.Broadcast(true);
		}

		OpenDoor(DeltaTime);
	}

}

void ADoor::OpenDoor(float DeltaTime)
{
	IsOpen = true;
	CurrentYaw = FMath::Lerp(CurrentYaw, TargetYaw, DeltaTime * DoorOpenSpeed);
	FRotator DoorRotation = this->GetActorRotation();
	DoorRotation.Yaw = CurrentYaw;
	this->SetActorRotation(DoorRotation);
}


bool ADoor::CanOpen()
{

	for (int i = 0; i < RemainingEnemies.Num(); i++)
	{
		if (RemainingEnemies[i])
		{
			if (RemainingEnemies[i]->IsAlive)
			{
				return false;
			}
		}
	}

	return true;
}
