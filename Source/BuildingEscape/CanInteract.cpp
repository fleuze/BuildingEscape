// Fill out your copyright notice in the Description page of Project Settings.

#include "CanInteract.h"


// Sets default values for this component's properties
UCanInteract::UCanInteract()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCanInteract::BeginPlay()
{
	Super::BeginPlay();
	player = GetWorld()->GetFirstPlayerController();
	if (!player)
	{
		UE_LOG(LogTemp, Error, TEXT("CanInteract BeginPlay Player not found"));
		return;
	}
	// Input Controller pour bind Interact
	inputC = player->FindComponentByClass<UInputComponent>();	
	trigger = (ATriggerBox*)GetOwner();
	if (!trigger)
	{
		UE_LOG(LogTemp, Error, TEXT("CanInteract BeginPlay Trigger not found"));
		return;
	}
}
void UCanInteract::Interact()
{
	UE_LOG(LogTemp, Warning, TEXT("Interact"));
}

// Called every frame
void UCanInteract::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!trigger)
	{
		UE_LOG(LogTemp, Error, TEXT("CanInteract BeginPlay Trigger not found"));
		return;
	}
	trigger->GetOverlappingActors(overlappingActors);
	UE_LOG(LogTemp, Warning, TEXT("actor : %s"), overlappingActors.Num());
	if (overlappingActors.Num() == 1)
	{
		//TODO
		/*if (overlappingActors.)
		{

		}*/
	}

	
	/*if (!inputC)
	{
		UE_LOG(LogTemp, Error, TEXT("CanInteract BeginPlay InputC not found"));
		return;
	}
	inputC->BindAction("Interact", IE_Pressed, this, &UCanInteract::Interact);*/
	// ...
}

