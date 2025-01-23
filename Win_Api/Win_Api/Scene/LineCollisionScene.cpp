#include "framework.h"
#include "Math/Collider/Line.h"
#include "Math/Collider/CircleCollider.h"

#include "LineCollisionScene.h"

LineCollisionScene::LineCollisionScene()
{
	_line1 = make_shared<Line>(Vector(100, 100), Vector(100, 100));
	_line2 = make_shared<Line>(Vector(100, 500), Vector(700, 200));
	_collidePoint = make_shared<CircleCollider>(Vector(0, 0), 30);

}

LineCollisionScene::~LineCollisionScene()
{
}

void LineCollisionScene::Update()
{
	_line1->Update();
	_line2->Update();
	_collidePoint->Update();

	if (_line1->IsCollision(_line2))
	{
		_line1->SetRed();
		Vector temp;
		if (_line1->CollisionPoint(_line2, temp))
			_collidePoint->SetCenter(temp);

	}
	else
	{
		_line1->SetGreen();
		_collidePoint->SetCenter(0, 0);
	}
	_line1->end = mousePos;

	

}

void LineCollisionScene::Render(HDC hdc)
{

	_line1->Render(hdc);
	_line2->Render(hdc);
	_collidePoint->Render(hdc);
}
