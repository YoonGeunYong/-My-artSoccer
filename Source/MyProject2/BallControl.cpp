// Fill out your copyright notice in the Description page of Project Settings.


#include "BallControl.h"
#include "Kismet/GameplayStatics.h"
#include "Components/PrimitiveComponent.h"
#include "GameFramework/PlayerController.h"

// Sets default values for this component's properties
UBallControl::UBallControl()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("HitField"));
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
		CameraControler->bAutoManageActiveCameraTarget = false;
	}

	//if (CollisionSphere)
	//{
	//	GetOwner()->SetRootComponent(CollisionSphere);
	//	CollisionSphere->OnComponentBeginOverlap.AddDynamic(this, &UBallControl::OnOverlapBegin);
	//}

	//for (int i = 0; i < 12; i++)
	//{
	//	Players[i] =UGameplayStatics::GetPlayerPawn(this, i);
	//}
	

	// ...
	
}


// Called every frame
void UBallControl::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


//void UBallControl::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
//	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
//	bool bFromSweep, const FHitResult& SweepResult)
//{
//	// 충돌이 발생한 액터
//	AActor* CollidedActor = OtherActor;
//
//	// 현재 액터의 위치
//	FVector MyLocation = GetOwner()->GetActorLocation();
//
//	// 가장 가까운 액터
//	AActor* NearestActor = nullptr;
//
//	// 가장 가까운 액터와의 거리 제곱
//	float NearestDistanceSquared = TNumericLimits<float>::Max();
//
//	// 플레이어 액터를 순회하여 가장 가까운 액터를 찾습니다.
//	for (auto player : Players)
//	{
//		AActor* CurrentActor = player;
//		if (CurrentActor != GetOwner() && CurrentActor == CollidedActor)
//		{
//			float DistanceSquared = FVector::DistSquared(CurrentActor->GetActorLocation(), MyLocation);
//			if (DistanceSquared < NearestDistanceSquared)
//			{
//				NearestActor = CurrentActor;
//				NearestDistanceSquared = DistanceSquared;
//			}
//		}
//	}
//	//OtherActor = NearestActor;
//
//}