// Fill out your copyright notice in the Description page of Project Settings.


#include "MyStatComponent.h"
#include "MyGameInstance.h"
#include "MyCharacter.h"
// Sets default values for this component's properties
UMyStatComponent::UMyStatComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

}


// Called when the game starts
void UMyStatComponent::BeginPlay()
{
	Super::BeginPlay();
	GetData(_level);


	
}


// Called every frame
void UMyStatComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UMyStatComponent::GetData(int value)
{

	auto gameInstance = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());
	auto statInfo = gameInstance->GetStat_Level(value);

	_maxHp = statInfo.hp;
	_curHp = _maxHp;
	_atk = statInfo.atk;
	_maxExp = statInfo.exp;
}

int32 UMyStatComponent::AddCurHp(float amount, AActor* causer)
{
	int32 before = _curHp;
	_curHp += amount;

	
	if (_curHp < 0)
		_curHp = 0;
	if (_curHp > _maxHp)
		_curHp = _maxHp;
	


	UE_LOG(LogTemp, Log, TEXT(" Name :%s ,HP : %df"),*(GetOwner()->GetName()),_curHp );

	float ratio = _curHp / (float)_maxHp;
	if (_hpChanged.IsBound())
	{
		_hpChanged.Broadcast(ratio);
	}
	return before-_curHp;
}

void UMyStatComponent::AddExp(int32 value)
{
	_curExp += value;
	CheckLevelUp();
}

bool UMyStatComponent::CheckLevelUp()
{

	UE_LOG(LogTemp, Log, TEXT(" Check Level Up"));
	if (_maxExp <= _curExp)
	{
		_curExp -= _maxExp;
		LevelUp();
		CheckLevelUp();
		return true;
	}
	return false;
}

void UMyStatComponent::LevelUp()
{
	_level += 1;
	GetData(_level);

	UE_LOG(LogTemp, Log, TEXT(" Level Up"));
}

