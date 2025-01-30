#include "framework.h"

#include "Objects/Cannon/Cannon.h"

#include "CannonScene.h"

CannonScene::CannonScene()
{
	_cannon1 = make_shared<Cannon>();
	_cannon2 = make_shared<Cannon>();
	_cannon1->SetTurnFinish(&CannonScene::TurnFinish,this);
	_cannon2->SetTurnFinish(&CannonScene::TurnFinish, this);
	TurnFinish();
}

CannonScene::~CannonScene()
{
}

void CannonScene::Update()
{
	_cannon1->Update();
	_cannon2->Update();

}

void CannonScene::Render(HDC hdc)
{

	_cannon1->Render(hdc);
	_cannon2->Render(hdc);

}

void CannonScene::TurnFinish()
{
	_turn = !_turn;

	if (_turn)
	{
		_cannon1->TurnStart();
		_cannon2->TurnFinish();

	}
	else
	{
		_cannon2->TurnStart();
		_cannon1->TurnFinish();

	}
}
