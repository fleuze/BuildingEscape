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
	player = GetWorld()->GetFirstPlayerController()->GetPawn();
	UE_LOG(LogTemp, Warning, TEXT("%s"), *player->GetName());
	
	
	
}

void URotateDoor::OpenDoor()
{
	FRotator rotation(0, 90, 0);
	GetOwner()->SetActorRotation(rotation);
}
void URotateDoor::CloseDoor()
{
	FRotator rotation(0, 0, 0);
	GetOwner()->SetActorRotation(rotation);
}

// Called every frame
void URotateDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);


	trigger->ReceiveActorEndOverlap();
	if (trigger->IsOverlappingActor(player))
	{
		OpenDoor();
		lastTimeOpen = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("Porte ouverte"));
	}
	else
	{
		if (lastTimeOpen != 0)
		{
			delayfermeture = (closeDelay - (GetWorld()->GetTimeSeconds() - lastTimeOpen));
			UE_LOG(LogTemp, Warning, TEXT("Fermeture porte dans : %lf"), delayfermeture);
		}
		if (GetWorld()->GetTimeSeconds() - lastTimeOpen > closeDelay)
		{
			CloseDoor();
			lastTimeOpen = 0;
		}
		
	}
}

