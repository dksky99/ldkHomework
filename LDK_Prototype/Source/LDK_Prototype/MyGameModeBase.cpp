// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "MyTutoPawn.h"

#pragma region GameModeBase
/*
	게임모드 베이스 : 

	TSubclassOf : 클래스를 넣는다.


*/
#pragma endregion

AMyGameModeBase::AMyGameModeBase()
{


	//블루프린트 클래스 타입을 가져올때 _C를 붙여야한다.
	static ConstructorHelpers::FClassFinder<AMyTutoPawn> pawn(TEXT("/Script/Engine.Blueprint'/Game/Blueprints/BP_MyCharacter.BP_MyCharacter_C'"));

	if (pawn.Succeeded())
	{
		//게임이 시작할때 동적할당
		DefaultPawnClass = pawn.Class;

	}
	



}
