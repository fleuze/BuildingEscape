// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Actor.h"
#include "Runtime/Engine/Classes/Engine/TriggerBox.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerController.h"
#include "Runtime/Engine/Classes/Components/PrimitiveComponent.h"
#include "CalculateMass.h"
#include "Runtime/Core/Public/Containers/Array.h"
#include "RotateDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API URotateDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	URotateDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void OpenDoor();
	void CloseDoor();

	

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
private:
	UPROPERTY(VisibleAnywhere)
	float openAngle = 90;

	UPROPERTY(EditAnywhere)
	ATriggerBox* triggerMass = nullptr;

	UCalculateMass* calMass = nullptr;

	float lastTimeOpen = 0;

	UPROPERTY(EditAnywhere)
	float closeDelay;

	float delayfermeture;
	
};
