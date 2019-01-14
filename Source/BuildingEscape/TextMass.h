// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Runtime/Engine/Classes/Engine/TriggerBox.h"
#include "Runtime/Engine/Classes/Components/TextRenderComponent.h"
#include "CalculateMass.h"
#include "TextMass.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BUILDINGESCAPE_API UTextMass : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UTextMass();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void MajText();

private:
	UPROPERTY(EditAnywhere)
	ATriggerBox* triggerMass = nullptr;

	UCalculateMass* calMass = nullptr;

	UTextRenderComponent* textRender = nullptr;

};
