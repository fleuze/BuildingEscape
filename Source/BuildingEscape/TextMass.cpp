// Fill out your copyright notice in the Description page of Project Settings.

#include "TextMass.h"


// Sets default values for this component's properties
UTextMass::UTextMass()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTextMass::BeginPlay()
{
	Super::BeginPlay();
	textRender = GetOwner()->FindComponentByClass<UTextRenderComponent>();
	calMass = triggerMass->FindComponentByClass<UCalculateMass>();
	// ...
	
}


// Called every frame
void UTextMass::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	textRender->SetText(FText::AsNumber(FMath::RoundToFloat(calMass->GetMassInTrigger())));
	// ...
}

