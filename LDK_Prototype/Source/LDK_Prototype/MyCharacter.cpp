// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"

#include "Kismet/KismetMathLibrary.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"

#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Camera/CameraActor.h"

#include "Engine/DamageEvents.h"

#include "MyAnimInstance.h"
#include "MyStatComponent.h"
#include "MyPlayerController.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetMesh()->SetRelativeLocationAndRotation(FVector(0, 0, -88.0f), FRotator(0,  -90,0));

	_statComponent = CreateDefaultSubobject<UMyStatComponent>(TEXT("Stat"));

	//행렬의 종속?
	


	//블루프린트에서 스켈레탈 메쉬 설정.
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();


	auto animInstance = GetMesh()->GetAnimInstance();

	//애님인스턴스를 가져와 캐스팅 후 
	_animInstance = Cast<UMyAnimInstance>(animInstance);
	//델리게이트 바인드
	//_animInstance->_attackStart.BindUObject(this, &AMyCharacter::TestDelegate);
	//_animInstance->_tpd.BindUObject(this, &AMyCharacter::TestDelegate2);
	//_animInstance->_dmd.AddDynamic(this, &AMyCharacter::TestDelegate);
	_animInstance->_hitCallBack.BindUObject(this, &AMyCharacter::AttackHit);
	_animInstance->_deadCallBack.BindUObject(this, &AMyCharacter::DeadActionEnd);
	_animInstance->OnMontageEnded.AddDynamic(this, &AMyCharacter::AttackEnd);

	_statComponent->_deadEvent.AddUObject(this, &AMyCharacter::Dead);
	_statComponent->_deadEvent.AddUObject(_animInstance, &UMyAnimInstance::DeadEvent);
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);





}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	

}


void AMyCharacter::UpDown(float value)
{
	if (abs(value) < 0.01f)
	{
		return;
	}
	_vertical = value;
	FVector forward = GetActorForwardVector();
	//SetActorLocation(GetActorLocation() + forward * value*50 );
	AddMovementInput( forward * value* _statComponent->GetSpeed());
}

void AMyCharacter::RightLeft(float value)
{
	if (abs(value) < 0.01f)
	{
		return;
	}
	_horizontal = value;
	FVector right = GetActorRightVector();
	//SetActorLocation(GetActorLocation() + right * value*50);
	AddMovementInput( right * value* _statComponent->GetSpeed() );

}


void AMyCharacter::Dead()
{
	_isUnable = true;

	this->SetActorEnableCollision(false);
	if (_animInstance)
	{

		_animInstance->PlayAnimMontage();
		_animInstance->JumpToSection(_curAttackSection);
	}
}


void AMyCharacter::DeadActionEnd()
{
	this->SetActorHiddenInGame(true); 
	this->SetActorTickEnabled(false);



}

void AMyCharacter::TestDelegate()
{
	UE_LOG(LogTemp, Log, TEXT("Attack Start Delegate Test"));
}

int32 AMyCharacter::TestDelegate2(int32 a, int32 b)
{
	UE_LOG(LogTemp, Log, TEXT("Attack%d Start%d Delegate Test"),a,b);

	return -1;
}

void AMyCharacter::AttackEnd(UAnimMontage* Montage, bool bInterrupted)
{

	_isAttack = false;
}

void AMyCharacter::AttackHit()
{
	UE_LOG(LogTemp, Log, TEXT("%s : AttackHit"),*GetName() );


	FHitResult hitResult;
	FCollisionQueryParams params(NAME_None, false, this);

	float attackRange = 2000.0f;
	float attackRadius = 25.0f;
	FVector fwd = GetActorForwardVector();
	FQuat qRot = FQuat::FindBetweenVectors(FVector::UpVector, fwd);
	FVector start = GetActorLocation();
	FVector end = start + fwd * attackRange;
	FVector center = start + (end - start) * 0.5;

	bool bResult = GetWorld()->SweepSingleByChannel(
		OUT hitResult,
		start,
		end,
		FQuat::Identity,
		ECC_GameTraceChannel2,
		FCollisionShape::MakeCapsule(attackRadius, attackRange*0.5f),
		params
	);

	FColor drawColor = FColor::Green;
	if (bResult && hitResult.GetActor()->IsValidLowLevel())
	{
		drawColor = FColor::Red;

		AMyCharacter* victim = Cast<AMyCharacter>(hitResult.GetActor());
		if (victim)
		{

			FDamageEvent damageEvent;

			victim->TakeDamage(_statComponent->GetAtk(), damageEvent, GetController(), this);
		}

	}

	DrawDebugCapsule(GetWorld(), center, attackRange*0.5, attackRadius, qRot, drawColor, false, 3.0f);

}

float AMyCharacter::TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	//Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);

	int32 dmg=_statComponent->AddCurHp(-Damage,DamageCauser);

	//공격자가 플레이어라면
	auto attackerController = Cast<AMyPlayerController>(EventInstigator);
	if (attackerController)
	{
		if (_statComponent->IsDead())
		{
			_statComponent->_deadEvent.Broadcast();

			if (DamageCauser != nullptr)
			{
				AMyCharacter* temp = Cast<AMyCharacter>(DamageCauser);
				if (temp != nullptr)
				{
					temp->AddExp(100);
				}
			}
		}
	}
	

	return dmg;
}

void AMyCharacter::AddHp(int32 value)
{

	_statComponent->AddCurHp(value);
}

void AMyCharacter::AddExp(int32 value)
{

	_statComponent->AddExp(value);
}
