// Fill out your copyright notice in the Description page of Project Settings.

#include "Grabber.h"


// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();
	player = GetWorld()->GetFirstPlayerController();
	if (!player)
	{
		UE_LOG(LogTemp, Error, TEXT("Grabber BeginPlay Player not found"));
		return;
	}
	handle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	if (!handle)
	{
		UE_LOG(LogTemp, Error, TEXT("Grabber BeginPlay handle not found"));
		return;
	}
	// Input Controller pour bind Grabb et Released
	UInputComponent* inputC = GetOwner()->FindComponentByClass<UInputComponent>();
	if (!inputC)
	{
		UE_LOG(LogTemp, Error, TEXT("Grabber BeginPlay InputC not found"));
	}
	inputC->BindAction("Grab", IE_Pressed, this, &UGrabber::Grab);
	inputC->BindAction("Grab", IE_Released, this, &UGrabber::Released);
}

void UGrabber::Released()
{
	if (!handle)
	{
		UE_LOG(LogTemp, Error, TEXT("Grabber Released handle not found"));
		return;
	}
	handle->ReleaseComponent();
	UE_LOG(LogTemp, Warning, TEXT("ReleasedGrab"));
}

void UGrabber::Grab()
{
	FHitResult hit;
	if (!player)
	{
		UE_LOG(LogTemp, Error, TEXT("Grabber BeginPlay Player not found"));
		return;
	}
	player->GetPlayerViewPoint(startPoint, playerRot);
	endPoint = startPoint + playerRot.Vector()*maxDist;
	//UE_LOG(LogTemp, Warning, TEXT("Location : %s Rotation : %s"), *startPoint.ToString(), *playerRot.ToString());
	//DrawDebugLine(GetWorld(), startPoint, endPoint, FColor::Red, false, -1, 0, 5);

	if (GetWorld()->LineTraceSingleByObjectType(hit, startPoint, endPoint, ECollisionChannel::ECC_PhysicsBody, FCollisionQueryParams(FName(), false, GetOwner())))
	{
		UE_LOG(LogTemp, Warning, TEXT("hit : %s"), *hit.GetActor()->GetName());
		if (!handle)
		{
			UE_LOG(LogTemp, Error, TEXT("Grabber Grab handle not found"));
			return;
		}
		handle->GrabComponent(hit.GetComponent(), NAME_None, hit.ImpactPoint, false);
	}
	UE_LOG(LogTemp, Warning, TEXT("BeginGrab"));
}



// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	if (!handle)
	{
		UE_LOG(LogTemp, Error, TEXT("Grabber EventTick handle not found"));
		return;
	}
	if (handle->GetGrabbedComponent() != nullptr)
	{
		if (!player)
		{
			UE_LOG(LogTemp, Error, TEXT("Grabber BeginPlay Player not found"));
			return;
		}
		player->GetPlayerViewPoint(startPoint, playerRot);
		endPoint = startPoint + playerRot.Vector()*maxDist;
		handle->SetTargetLocation(endPoint);
	}
	// ...
}

