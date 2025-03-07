// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAnimInstance.h"
#include "Animation/AnimMontage.h"
#include "MyCharacter.h"
#include "GameFramework/PawnMovementComponent.h"

UMyAnimInstance::UMyAnimInstance()
{
}

void UMyAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	//스피드 확인
	auto pawn=TryGetPawnOwner();

	AMyCharacter* character = Cast<AMyCharacter>(pawn);
	if (character != nullptr)
	{
		_speed = character->GetVelocity().Size();
		_isFalling = character->GetMovementComponent()->IsFalling();
		_vertical = character->MyVertical();
		_horizontal = character->MyHorizontal();

	}


}

void UMyAnimInstance::PlayAnimMontage()
{
	if (_animMontage == nullptr)
		return;

	//몽타주가 실행주인가.
	if (!Montage_IsPlaying(_animMontage))
	{
		//_attackStart.Execute();
		//_tpd.Execute(10, 20);
		//_dmd.Broadcast();
		
		//몽타주 실행.
		Montage_Play(_animMontage);
	}

}

void UMyAnimInstance::JumpToSection(int32 sectionIndex)
{
	FName sectionName = FName(*FString::Printf(TEXT("Section%d"), sectionIndex));

	Montage_JumpToSection(sectionName);
}


void UMyAnimInstance::AnimNotify_Fire()
{
	if(_hitCallBack.IsBound())
	_hitCallBack.Execute();

	
}

void UMyAnimInstance::AnimNotify_Dead()
{
	if (_deadCallBack.IsBound())
	_deadCallBack.Execute();
}

void UMyAnimInstance::DeadEvent()
{
	_isDead = true;
}
