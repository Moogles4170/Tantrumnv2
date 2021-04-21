// Fill out your copyright notice in the Description page of Project Settings.


#include "TatrumnLevelEndVolume.h"
#include "TantrumnCharacterBase.h"
#include "TantrumnGameModeBase.h"

ATatrumnLevelEndVolume::ATatrumnLevelEndVolume()
{
	OnActorBeginOverlap.AddDynamic(this, &ATatrumnLevelEndVolume::OnOverlapBegin);

}

void ATatrumnLevelEndVolume::BeginPlay()
{
	Super::BeginPlay();
	GameModeRef = GetWorld()->GetAuthGameMode<ATantrumnGameModeBase>();
}

void ATatrumnLevelEndVolume::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OtherActor == Cast<ATantrumnCharacterBase>(OtherActor))
	{
		GameModeRef->PlayerReachedEnd();
	}
}

