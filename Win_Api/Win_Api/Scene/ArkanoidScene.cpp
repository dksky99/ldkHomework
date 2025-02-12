#include "framework.h"
#include "Math/Collider/CircleCollider.h"
#include "Objects/Arkanoid/Arkanoid_Player.h"
#include "Objects/Arkanoid/Arkanoid_Ball.h"
#include "Objects/Arkanoid/Arkanoid_Wall.h"
#include "Objects/Arkanoid/Arkanoid_Map.h"
#include "ArkanoidScene.h"

ArkanoidScene::ArkanoidScene()
{

	_player = make_shared<Arkanoid_Player>();
	_player->Init();

	_player->SetBallDeadEvent(bind(&ArkanoidScene::BallDead, this));
	
	_map = make_shared<Arkanoid_Map>();
	_map->Init(_player);

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
	_map->Update();
	CollisionCheck();
}

void ArkanoidScene::Render(HDC hdc)
{
	_player->Render(hdc);
	for (auto ui : _hpUI)
	{
		ui->Render(hdc);
	}

	_map->Render(hdc);
}

void ArkanoidScene::CollisionCheck()
{
	for (auto ball : _player->GetBalls())
	{
		if (ball->isActive == false)
			continue;
		_player->IsCollision(ball);
		
		_map->IsCollision_Walls(ball);

	}
	_map->IsCollidsion_Items(_player);
	
}

void ArkanoidScene::BallDead()
{
	if (_lifeCount <= 0)
		return;

	for (auto ball : _player->GetBalls())
	{
		if (ball->IsFired())
		{
			return;
		}
	}

	_lifeCount--;
	_hpUI[_lifeCount]->SetRed();
	_player->GetBalls()[0]->isActive = true;
}
