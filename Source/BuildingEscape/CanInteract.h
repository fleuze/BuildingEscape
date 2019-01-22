// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Runtime/Engine/Classes/Engine/TriggerBox.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"
#include "CanInteract.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDigitEvent);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UCanInteract : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCanInteract();
	UPROPERTY(BlueprintReadWrite)
	int numberDigit = 0;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void Interact();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	// Pour Récupérer le player viewPoint
	APlayerController* player = nullptr;
	TSet<AActor*> overlappingActors;
	ATriggerBox* trigger = nullptr;
	UInputComponent* inputC = nullptr;

	UPROPERTY(BlueprintAssignable)
	FDigitEvent openRequestWidget;
	UPROPERTY(BlueprintAssignable)
	FDigitEvent closeRequestWidget;
	UPROPERTY(BlueprintAssignable)
	FDigitEvent openRequestInteract;
	UPROPERTY(BlueprintAssignable)
	FDigitEvent closeRequestInteract;

	

	int cptNumberActorOverlaps = 0;

};
