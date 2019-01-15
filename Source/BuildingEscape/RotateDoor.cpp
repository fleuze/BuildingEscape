// Fill out your copyright notice in the Description page of Project Settings.

#include "RotateDoor.h"


// Sets default values for this component's properties
URotateDoor::URotateDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void URotateDoor::BeginPlay()
{
	Super::BeginPlay();
	if (!triggerMass)
	{
		UE_LOG(LogTemp, Error, TEXT("TriggerMass RotateDoor not found"));
		return;
	}
	calMass = triggerMass->FindComponentByClass<UCalculateMass>();
	if (!calMass)
	{
		UE_LOG(LogTemp, Error, TEXT("calMass RotateDoor not found"));
		return;
	}
}
// Called every frame
void URotateDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!calMass)
	{
		UE_LOG(LogTemp, Error, TEXT("CalMass RotateDoor not found"));
		return;
	}
	if (calMass->GetMassInTrigger()==0)
	{
		openRequest.Broadcast();
		//UE_LOG(LogTemp, Warning, TEXT("Porte ouverte"));
	}
	else
	{
		closeRequest.Broadcast();
	}
}

