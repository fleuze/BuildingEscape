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
	if (!inputC)
	{
		UE_LOG(LogTemp, Error, TEXT("CanInteract BeginPlay InputC not found"));
		return;
	}
	inputC->BindAction("Interact", IE_Pressed, this, &UCanInteract::Interact);
}
void UCanInteract::Interact()
{
	UE_LOG(LogTemp, Warning, TEXT("Interact"));
	if (!player)
	{
		UE_LOG(LogTemp, Error, TEXT("CanInteract Interact Player not found"));
		return;
	}
	openRequestInteract.Broadcast();
	//openRequestInteract.Broadcast();
}

// Called every frame
void UCanInteract::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!player)
	{
		UE_LOG(LogTemp, Error, TEXT("CanInteract Event tick Player not found"));
		return;
	}

	if (!trigger)
	{
		UE_LOG(LogTemp, Error, TEXT("CanInteract BeginPlay Trigger not found"));
		return;
	}
	trigger->GetOverlappingActors(overlappingActors);
	if (overlappingActors.Num() == 1 && overlappingActors.Array()[0]->GetName() == "BP_Pawn_C_0")
	{
		// Ici on est sûre que le player est dans le trigger et uniquement lui donc affichage du widget
		openRequestWidget.Broadcast();
		
	}
	else
	{
		closeRequestWidget.Broadcast();
	}
}

