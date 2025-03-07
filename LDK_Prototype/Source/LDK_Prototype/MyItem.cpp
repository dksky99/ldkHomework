// Fill out your copyright notice in the Description page of Project Settings.


#include "MyItem.h"

#include "Components/CapsuleComponent.h"
#include "Engine/DamageEvents.h"

#include "MyCharacter.h"
#include "MyPlayer.h"
#include "MyPlayerController.h"
// Sets default values
AMyItem::AMyItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	 _locationMarker=CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	 _mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	 _collider = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Collider"));
	 SetRootComponent(_locationMarker);
	 _collider->SetupAttachment(RootComponent);
	 _mesh->SetupAttachment(_collider);




}

// Called when the game starts or when spawned
void AMyItem::BeginPlay()
{
	Super::BeginPlay();

	_collider->OnComponentBeginOverlap.AddDynamic(this, &AMyItem::OnlyCharacterOverlap);
	_defaultLoc = _collider->GetRelativeLocation();
}

// Called every frame
void AMyItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	time += DeltaTime;
	if (time > 4*PI)
		time -= 4*PI;
	
	Rotate(DeltaTime);

	Move(DeltaTime);
}



void AMyItem::Rotate(float DeltaTime)
{


		FRotator rot = FRotator(0, 1, 0);
		FRotator rot2 = FRotator(0, -1, 0);

		_mesh->SetRelativeRotation(_mesh->GetRelativeRotation() + rot2 * 10 * 10 * DeltaTime);
}

void AMyItem::Move(float DeltaTime)
{


	FVector curLocation = _defaultLoc;
	FVector destLocation = _defaultLoc+(FVector::UpVector * FMath::Sin(time*0.5) * _sinMove);

	_collider->SetRelativeLocation(destLocation);
}

void AMyItem::OnlyCharacterOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AMyPlayer* user = Cast< AMyPlayer>(OtherActor);
	if (user == nullptr)
		return;

	AMyPlayerController* controller = Cast< AMyPlayerController>(user->GetController());
	if (controller == nullptr)
		return;
	if (user&&controller)
	{
		user->AddItem(this);
		//ItemEffect(user);
		GetItem();
		
	}

}

void AMyItem::ItemEffect(AMyCharacter* user)
{
	user->AddHp(20);
}

void AMyItem::GetItem()
{

	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);
}

void AMyItem::DropItem()
{
	FindGround();
	SetActorHiddenInGame(false);
	SetActorEnableCollision(true);
}

void AMyItem::FindGround()
{

	// 레이캐스트 예시 코드 (C++)

	FVector Start = GetActorLocation(); // 시작점, 예: 캐릭터 위치
	FVector End = Start - FVector(0.f, 0.f, 1000.f); // 끝점, 예: 땅 방향으로 1000 유닛 내려갑니다.

	FCollisionQueryParams CollisionParams;
	CollisionParams.AddIgnoredActor(this); // 현재 객체를 무시하도록 설정

	FHitResult HitResult;
	bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECC_GameTraceChannel4, CollisionParams);

	if (bHit)
	{
		FVector GroundLocation = HitResult.ImpactPoint; // 충돌한 지점의 위치
		UE_LOG(LogTemp, Warning, TEXT("Ground Loc: %s"), *GroundLocation.ToString());
		SetActorLocation(GroundLocation + FVector::UpVector * _defaultY);
	}

}

