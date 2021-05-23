// Fill out your copyright notice in the Description page of Project Settings.


#include "TatrumnLevelEndVolume.h"
#include "TantrumnCharacterBase.h"
#include "TantrumnGameStateBase.h"

ATatrumnLevelEndVolume::ATatrumnLevelEndVolume()
{
	OnActorBeginOverlap.AddDynamic(this, &ATatrumnLevelEndVolume::OnOverlapBegin);
}

void ATatrumnLevelEndVolume::BeginPlay()
{
	Super::BeginPlay();
}

void ATatrumnLevelEndVolume::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
	if (HasAuthority())
	{
		if (ATantrumnGameStateBase* TantrumnGameState = GetWorld()->GetGameState<ATantrumnGameStateBase>())
		{
			ATantrumnCharacterBase* TantrumnCharacterBase = Cast<ATantrumnCharacterBase>(OtherActor);
			TantrumnGameState->OnPlayerReachedEnd(TantrumnCharacterBase);
		}
	}
}

