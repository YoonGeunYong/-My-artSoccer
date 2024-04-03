// Fill out your copyright notice in the Description page of Project Settings.


#include "BallControl.h"
#include "Kismet/GameplayStatics.h"
#include "Components/PrimitiveComponent.h"

// Sets default values for this component's properties
UBallControl::UBallControl()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	
	// ...
}


// Called when the game starts
void UBallControl::BeginPlay()
{
	Super::BeginPlay();

	APlayerController* CameraControler = UGameplayStatics::GetPlayerController(this, 0);
	if (CameraControler)
	{
		CameraControler->SetViewTargetWithBlend(GetOwner(), 0.0f);
	}

	for (int i = 0; i < 12; i++)
	{
		Players[i] =UGameplayStatics::GetPlayerPawn(this, i);
	}
	TArray<UPrimitiveComponent*> Components;
	Components = GetComponentLevel

	// ...
	
}


// Called every frame
void UBallControl::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	for (int i = 0; i < 12; i++)
	{
		GetOwner()->FindComponentByClass<>->NotifyActorBeginOverlap()
	}
}
