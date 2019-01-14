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
	if (!textRender)
	{
		UE_LOG(LogTemp, Error, TEXT("Calculate BeginPlay TextRender not found"));
		return;
	}
	calMass = triggerMass->FindComponentByClass<UCalculateMass>();
	if (!calMass)
	{
		UE_LOG(LogTemp, Error, TEXT("Calculate BeginPlay calMass not found"));
		return;
	}
	// ...
	
}


// Called every frame
void UTextMass::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	MajText();
	// ...
}

void UTextMass::MajText()
{
	if (!textRender)
	{
		UE_LOG(LogTemp, Error, TEXT("Calculate BeginPlay TextRender not found"));
		return;
	}
	textRender->SetText(FText::AsNumber(FMath::RoundToFloat(calMass->GetMassInTrigger())));
}

