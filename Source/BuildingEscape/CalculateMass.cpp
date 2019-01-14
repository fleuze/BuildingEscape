// Fill out your copyright notice in the Description page of Project Settings.

#include "CalculateMass.h"


// Sets default values for this component's properties
UCalculateMass::UCalculateMass()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCalculateMass::BeginPlay()
{
	Super::BeginPlay();


	trigger = (ATriggerBox*)GetOwner();
	if (!trigger)
	{
		UE_LOG(LogTemp, Error, TEXT("Calculate BeginPlay Trigger not found"));
		return;
	}
	// ...

}


// Called every frame
void UCalculateMass::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

float UCalculateMass::GetMassInTrigger()
{
	float totalMass = 0;
	TSet<AActor*> overlappingActors;
	if (!trigger)
	{
		UE_LOG(LogTemp, Error, TEXT("Calculate BeginPlay Trigger not found"));
		return 0;
	}
	trigger->GetOverlappingActors(overlappingActors);
	for (AActor* actor : overlappingActors)
	{
		totalMass += actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
	}
	return massMin - totalMass;
}

