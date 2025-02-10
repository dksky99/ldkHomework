#include "framework.h"
#include "Objects/Arkanoid/Arkanoid_Player.h"
#include "Objects/Arkanoid/Arkanoid_Ball.h"
#include "Objects/Arkanoid/Arkanoid_Wall.h"
#include "ArkanoidScene.h"

ArkanoidScene::ArkanoidScene()
{

	_player = make_shared<Arkanoid_Player>();

	
	for (int i = 0;i < _poolCount;i++)
	{
		int y = i / 7;
		int x = i % 7;
		y *= 20;
		x *= 50;
		y += 10;
		x += 25;
		y += 100;
		_walls.push_back(make_shared<Arkanoid_Wall>(Vector(x, y)));
		_walls.back()->SetPos(Vector(x, y));
	}


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
}

void ArkanoidScene::Render(HDC hdc)
{
	_player->Render(hdc);
	for (auto wall : _walls)
	{
		wall->Render(hdc);
	}
}

void ArkanoidScene::CollidsionCheck()
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
