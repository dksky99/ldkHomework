#include "framework.h"
#include "Objects/Arkanoid/Arkanoid_Player.h"
#include "Objects/Arkanoid/Arkanoid_Ball.h"
#include "Objects/Arkanoid/Arkanoid_Wall.h"
#include "ArkanoidScene.h"

ArkanoidScene::ArkanoidScene()
{

	_player = make_shared<Arkanoid_Player>();
}

ArkanoidScene::~ArkanoidScene()
{
}

void ArkanoidScene::Update()
{
	_player->Update();
}

void ArkanoidScene::Render(HDC hdc)
{
	_player->Render(hdc);
}
