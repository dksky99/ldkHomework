#include "framework.h"
#include "Math/Collider/CircleCollider.h"
#include "Objects/Arkanoid/Arkanoid_Player.h"
#include "Objects/Arkanoid/Arkanoid_Ball.h"
#include "Objects/Arkanoid/Arkanoid_Wall.h"
#include "ArkanoidScene.h"

ArkanoidScene::ArkanoidScene()
{

	_player = make_shared<Arkanoid_Player>();


	_player->SetBallDeadEvent(bind(&ArkanoidScene::BallDead, this));
	
	for (int i = 0;i < _poolCount;i++)
	{
		int y = i / 7;
		int x = i % 7;
		y *= 40;
		x *= 100;
		y += 20;
		x += 50;
		y += 100;
		_walls.push_back(make_shared<Arkanoid_Wall>(Vector(x, y)));
		_walls.back()->SetPos(Vector(x, y));
	}

	_hpUI.push_back(make_shared<CircleCollider>(Vector(20, 20), 15));
	_hpUI.push_back(make_shared<CircleCollider>(Vector(60, 20), 15));
	_hpUI.push_back(make_shared<CircleCollider>(Vector(100, 20), 15));
	_hpUI[0]->SetGreen();
	_hpUI[1]->SetGreen();
	_hpUI[2]->SetGreen();

}

ArkanoidScene::~ArkanoidScene()
{
}

void ArkanoidScene::Update()
{
	_player->Update();
	for (auto wall :_walls)
	{
		wall->Update();
	}
	CollisionCheck();
}

void ArkanoidScene::Render(HDC hdc)
{
	_player->Render(hdc);
	for (auto ui : _hpUI)
	{
		ui->Render(hdc);
	}

	for (auto wall : _walls)
	{
		wall->Render(hdc);
	}
}

void ArkanoidScene::CollisionCheck()
{
	for (auto ball : _player->GetBalls())
	{
		if (ball->isActive == false)
			continue;
		_player->IsCollision(ball);
		for (auto wall : _walls)
		{
			wall->IsCollision(ball);
		}

	}
}

void ArkanoidScene::BallDead()
{
	if (_lifeCount <= 0)
		return;
	_lifeCount--;
	_hpUI[_lifeCount]->SetRed();
}
