// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Runtime/Engine/Classes/Engine/TriggerBox.h"
#include "GameFramework/Actor.h"
#include "Runtime/Engine/Classes/Components/PrimitiveComponent.h"
#include "CalculateMass.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UCalculateMass : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCalculateMass();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	float GetMassInTrigger();

private:
	UPROPERTY(EditAnywhere)
	float massMin = 150.f;

	ATriggerBox* trigger = nullptr;
	
};
