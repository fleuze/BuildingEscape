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
	handle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	if (!handle)
	{
		UE_LOG(LogTemp, Error, TEXT("Error : UPhysicsHandleComponent"));
	}
	// Input Controller pour bind Grabb et Released
	UInputComponent* inputC = GetOwner()->FindComponentByClass<UInputComponent>();
	if (!inputC)
	{
		UE_LOG(LogTemp, Error, TEXT("Error : UInputComponent"));
	}
	inputC->BindAction("Grab", IE_Pressed, this, &UGrabber::Grab);
	inputC->BindAction("Grab", IE_Released, this, &UGrabber::Released);
}

void UGrabber::Released()
{
	UE_LOG(LogTemp, Warning, TEXT("ReleasedGrab"));
}

void UGrabber::Grab()
{
	FRotator playerRot;
	FVector startPoint;
	FVector endPoint;
	FHitResult hit;

	player->GetPlayerViewPoint(startPoint, playerRot);
	//UE_LOG(LogTemp, Warning, TEXT("Location : %s Rotation : %s"), *startPoint.ToString(), *playerRot.ToString());
	endPoint = startPoint + playerRot.Vector()*maxDist;

	//DrawDebugLine(GetWorld(), startPoint, endPoint, FColor::Red, false, -1, 0, 5);

	if (GetWorld()->LineTraceSingleByObjectType(hit, startPoint, endPoint, ECollisionChannel::ECC_PhysicsBody, FCollisionQueryParams(FName(), false, GetOwner())))
	{
		UE_LOG(LogTemp, Warning, TEXT("hit : %s"), *hit.GetActor()->GetName());
		handle->GrabComponent(hit.GetComponent(), NAME_None, hit.GetActor()->GetActorLocation(), true);
	}
	UE_LOG(LogTemp, Warning, TEXT("BeginGrab"));
}



// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

