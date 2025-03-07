// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTutoActor.h"

#pragma region Blueprint
/*
	언리얼의 고유 클래스들은 UObject를 상속받아서 만들어진다.
	모든 블루프린트는 c++ 클래스를 상속받아서 만들어진다.

	new를 사용해 동적할당하는것은 지양한다.

	shared_ptr은 사용하지 못한다. 이건 std 라이브러리를 인클루드해야 사용가능. 
	언리얼 전용의 스마트포인터가 따로있다.



*/
#pragma endregion




// Sets default values
AMyTutoActor::AMyTutoActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	_mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));






}

// Called when the game starts or when spawned
void AMyTutoActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyTutoActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	FRotator rot = FRotator(0, 1, 0);
	FRotator curRotation = GetActorRotation();
	FRotator destRot = curRotation + rot * _rotSpeed * DeltaTime;
	SetActorRotation(destRot);


}

