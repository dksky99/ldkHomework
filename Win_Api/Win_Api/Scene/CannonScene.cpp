#include "framework.h"

#include "Objects/Cannon/Cannon.h"

#include "CannonScene.h"

CannonScene::CannonScene()
{
	_cannon1 = make_shared<Cannon>();
	_cannon2 = make_shared<Cannon>();
	//functional�� ����ϱ����� �Լ��� ��ü�� ���� ��� �Ű������� ������ ���.
	_cannon1->SetTurnFinish(bind( & CannonScene::TurnFinish,this));
	_cannon2->SetTurnFinish(bind( & CannonScene::TurnFinish, this));
	TurnFinish();
}

CannonScene::~CannonScene()
{
}

void CannonScene::Update()
{
	_cannon1->Update();
	_cannon2->Update();

	CollisionCheck();

}

void CannonScene::Render(HDC hdc)
{

	_cannon1->Render(hdc);
	_cannon2->Render(hdc);

}

void CannonScene::TurnFinish()
{
	//��ȯ����
	_curTurn = static_cast<CannonScene::ECannonTurn>((_curTurn + 1) % ECannonTurn::TURNCOUNT);
	switch (_curTurn)
	{
	case CannonScene::ONE:
	{
		_cannon1->TurnStart();
		_cannon2->TurnFinish();

	}
		break;
	case CannonScene::TWO:
	{
		_cannon2->TurnStart();
		_cannon1->TurnFinish();

	}
		break;


	default:
		break;
	}

}

void CannonScene::CollisionCheck()
{

	for (auto ball : _cannon1->GetBalls())
	{
		_cannon2->IsCollision(ball);
	}
	for (auto ball : _cannon2->GetBalls())
	{
		_cannon1->IsCollision(ball);
	}
}
