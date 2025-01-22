#include "framework.h"
#include "Math/Collider/CircleCollider.h"
#include "Math/Collider/RectCollider.h"

#include "CollisionScene.h"

CollisionScene::CollisionScene()
{
	_circle = make_shared<CircleCollider>(450, 500, 100);
	_movingCircle = make_shared<CircleCollider>(0, 0, 60);


	_rect = make_shared<RectCollider>(750, 500, 100,100);
	_movingRect = make_shared<RectCollider>(0, 0, 60,60);
}

CollisionScene::~CollisionScene()
{
}

void CollisionScene::Update()
{
	if (_circle->IsCollision(_movingRect))
	{
		_circle->SetRed();
	}
	else
	{
		_circle->SetGreen();
	}
	_movingRect->SetCenter(mousePos);
	_circle->Update();
	_movingCircle->Update();
	_rect->Update();
	_movingRect->Update();
}

void CollisionScene::Render(HDC hdc)
{

	_circle->Render(hdc);
	_movingCircle->Render(hdc);

	_rect->Render(hdc);
	_movingRect->Render(hdc);
}
