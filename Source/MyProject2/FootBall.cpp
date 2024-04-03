// Fill out your copyright notice in the Description page of Project Settings.


#include "FootBall.h"
#include "Components/PrimitiveComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"

// Sets default values
AFootBall::AFootBall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("HitField"));
	RootComponent = CollisionSphere;

}

// Called when the game starts or when spawned
void AFootBall::BeginPlay()
{
	Super::BeginPlay();
	
	if (CollisionSphere)
	{
		CollisionSphere->OnComponentBeginOverlap.AddDynamic(this, &AFootBall::OnOverlapBegin);
	}

	GetComponents<UPrimitiveComponent>(PrimitiveComponents);

	for (UPrimitiveComponent* PrimitiveComponent : PrimitiveComponents)
	{
		PrimitiveComponent->OnComponentBeginOverlap.AddDynamic(this, &AFootBall::OnOverlapBegin);
	}
}

// Called every frame
void AFootBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFootBall::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult& SweepResult)
{
	UWorld* World = GetWorld();
	for (auto player : PrimitiveComponents)
	{
		if (player->GetOwner() == OtherActor)
		{
			
			//GetOwner()->SetActorLocation();
		}
	}
	// 충돌이 발생한 액터
	AActor* CollidedActor = OtherActor;

	// 현재 액터의 위치
	FVector MyLocation = GetActorLocation();

	// 가장 가까운 액터
	AActor* NearestActor = nullptr;

	// 가장 가까운 액터와의 거리 제곱
	float NearestDistanceSquared = TNumericLimits<float>::Max();

	// 모든 액터를 순회하여 가장 가까운 액터를 찾습니다.
	for (TActorIterator<AActor> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		AActor* CurrentActor = *ActorItr;
		if (CurrentActor != this && CurrentActor != CollidedActor)
		{
			float DistanceSquared = FVector::DistSquared(CurrentActor->GetActorLocation(), MyLocation);
			if (DistanceSquared < NearestDistanceSquared)
			{
				NearestActor = CurrentActor;
				NearestDistanceSquared = DistanceSquared;
			}
		}
	}

}