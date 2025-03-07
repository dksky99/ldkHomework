// Fill out your copyright notice in the Description page of Project Settings.



#include "MyTutoPawn.h"

#include "Kismet/KismetMathLibrary.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"

#pragma region Actor
/*
	액터가 월드에 존재하려면 transform이 있어야함
	액터가 눈에 보이려면 색을 칠하려면
	1. 메쉬가 있어야한다,
	2. 마테리얼이 있어야한다
	3. 트랜스폼이 있어야한다.
	메쉬 : 삼각형이 모여 형태를 만든것?
	메쉬가 없으면 크기도 없고 위치도 회전도 필요없어 트랜스폼이 존재하지 않는다.
	마테리얼 :정점 3개가모여 삼각형이 만들어지면 그 위에 사진을 올리는것.
	재질, 색상, 텍스쳐, 금속성 등 다양한것을 적용할 수 있다.



	UClass : UObject를 상속받는 클래스에 붙이는 키워드
	이걸 붙이는 이유
	1.리플렉션을 위해 사용.
	2. 가베지컬랙션을 위해 사용
	리플렉션(reflection) :
	c#은 코드를 작성하면 메타데이터가 생김 그걸이용해 리플렉션을 할 수 있음. 하지만 c++엔 그런기능이 없음. 위 키워드를 통해 리플렉션을 구현한것.

	UPROPERTY : UObject를 상속받는 필드에 반드시 붙여주는 키워드
	안붙이면 가베지 컬랙터의 도움을 못받을 수 있따.
	혹은 리플렉션이 필요한 필드에 붙여서 에디터에서 값을 바꿀수 있게 할 수 있다.
	
	



	언리얼은 fps게임을 만들다 생긴 게임엔진이라 fps의 설정을 좀 따름
	GameModeBase에서 DefaultPawn을 자동으로 생성해줌

	Rotation:
	Yaw 정면을기준으로 좌우로 흔듬
	Pitch : 정면을 기준으로 고개를 끄덕임
	Roll :정면을 기준으로 고개를 좌우로 까딱임

	deltaTime :시간의 변화량
	장비의 상황과 스펙에 따라 한 프레임사이에 걸리는 시간에 차이가 있어 
	그것에 따라 게임의 상황이 달라지지 않도록 하기위해 필요.

*/
#pragma endregion



// Sets default values
AMyTutoPawn::AMyTutoPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// C++ 코드 예시
	_locationMarker = CreateDefaultSubobject<USceneComponent>(TEXT("LocationMarker"));
	RootComponent = _locationMarker;


	//컴포넌트 생성. 동적할당하는것과 같음.
	_mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	_mesh->SetupAttachment(RootComponent);  // 루트 컴포넌트에 첨부
	_mesh->SetRelativeLocation(FVector(0, 0, 0));  // 위치 설정



	//sm에 해당 경로의 UStaticMesh, object를 갖고오는 방법. 생성자에서만 사용가능하다. 그래서 ConstructorHelper
	static ConstructorHelpers::FObjectFinder<UStaticMesh> sm(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Props/SM_Chair.SM_Chair'"));
	
	if (sm.Succeeded())
	{
		_mesh->SetStaticMesh(sm.Object);

		
	}
	UE_LOG(LogTemp, Log, TEXT("Hello World Constructor"));
}

// Called when the game starts or when spawned
void AMyTutoPawn::BeginPlay()
{
	Super::BeginPlay();


	UE_LOG(LogTemp, Log, TEXT("Hello World Begin"));
}

// Called every frame
void AMyTutoPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	Revolution_Rotation(DeltaTime);



}

// Called to bind functionality to input
void AMyTutoPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	////Delegate : 대리자, Callable 객체=> 콜백함수 : 사장된 방법.
	//PlayerInputComponent->BindAxis(TEXT("UpDown"), this, &AMyTutoPawn::UpDown);

	//Pawn
	//- Controller로 움직일 수 있음.

	//입력 바인드.
	UEnhancedInputComponent* enhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (enhancedInputComponent)
	{
		enhancedInputComponent->BindAction(_moveAction, ETriggerEvent::Triggered, this, &AMyTutoPawn::Move);
	}
	

}

void AMyTutoPawn::Revolution_Rotation(float DeltaTime)
{
	if (GetController())
		return;

	//부모가 있는지 확인. 
	if (GetAttachParentActor() == nullptr)
	{
		FVector curLocation = GetActorLocation();
		FVector destLocation = curLocation + FVector::ForwardVector * _moveSpeed * DeltaTime;

		//로컬 로케이션을 변화하는 함수. 계층구조로 달아놨을때 예측이 힘듬.
		SetActorLocation(destLocation);


		FRotator rot = FRotator(0, 1, 0);
		FRotator rot2 = FRotator(0, -1, 0);
		FRotator curRotation = GetActorRotation();
		FRotator destRot = curRotation + rot * _rotSpeed * DeltaTime;
		SetActorRotation(destRot);
		//위 아래의 2개의 코드는 같은효과
		//AddActorLocalRotation(rot * _rotSpeed * DeltaTime);

		_mesh->SetRelativeRotation(_mesh->GetRelativeRotation() + rot2 * 10 * _rotSpeed * DeltaTime);

	}
	else
	{
		FVector paretntV = GetAttachParentActor()->GetActorLocation();
		FVector myV = GetActorLocation();	//월드 로케이션을 가져옴

		FRotator rot = UKismetMathLibrary::FindLookAtRotation(myV, paretntV);
		SetActorRotation(rot);



	}
}

void AMyTutoPawn::Temp()
{
	UE_LOG(LogTemp, Error, TEXT("temp"));
}

void AMyTutoPawn::UpDown(float value)
{
	if (abs(value) < 0.01f)
	{
		return;
	}
	FVector forward = GetActorForwardVector();
	SetActorLocation(GetActorLocation() + forward * value * _moveSpeed);
}

void AMyTutoPawn::RightLeft(float value)
{
	if (abs(value) < 0.01f)
	{
		return;
	}

	FVector right = GetActorRightVector();
	SetActorLocation(GetActorLocation() + right * value * _moveSpeed);

}

void AMyTutoPawn::Move(const FInputActionValue& value)
{

	FVector2D moveVector = value.Get<FVector2D>();
	if (Controller != nullptr)
	{
		if (moveVector.Length() > 0.01f)
		{
			UE_LOG(LogTemp, Log, TEXT("X :%f "),moveVector.X);
			UE_LOG(LogTemp, Log, TEXT("Y :%f "),moveVector.Y);
			//액터의 로컬좌표의 전방과 우측을 월드좌표로 변환한 값
			//AddMovementInput(GetActorForwardVector(), moveVector.Y);
			//AddMovementInput(GetActorRightVector(), moveVector.X);
			UpDown(moveVector.X);
			RightLeft(moveVector.Y);

		}
	}


}

