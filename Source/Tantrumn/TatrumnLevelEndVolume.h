// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerVolume.h"
#include "TatrumnLevelEndVolume.generated.h"

class ATantrumnGameModeBase;

UCLASS()
class TANTRUMN_API ATatrumnLevelEndVolume : public ATriggerVolume
{
	GENERATED_BODY()
	
public:

	ATatrumnLevelEndVolume();

protected:
	virtual void BeginPlay() override;

private:

	//Custom Overlap funtion to override the Actor BeginOverlap version
	UFUNCTION()
	void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);

	ATantrumnGameModeBase* GameModeRef;
};
