#include "framework.h"
#include "Math/Collider/RectCollider.h"
#include "Objects/Arkanoid/Arkanoid_Ball.h"
#include "Arkanoid_Wall.h"

Arkanoid_Wall::Arkanoid_Wall()
{
	isActive = true;

	_collider = make_shared<RectCollider>(WIN_CENTER, Vector(50,20));

	

}

Arkanoid_Wall::Arkanoid_Wall(Vector pos)
{
	isActive = true;

	_collider = make_shared<RectCollider>(pos, Vector(50, 20));


}

Arkanoid_Wall::~Arkanoid_Wall()
{
}

void Arkanoid_Wall::SetPos(Vector pos)
{
	_collider->SetCenter(pos); 
}

void Arkanoid_Wall::Update()
{
	_collider->Update();
}

void Arkanoid_Wall::Render(HDC hdc)
{
	_collider->Render(hdc);
}

bool Arkanoid_Wall::IsCollision(shared_ptr<class Arkanoid_Ball> ball)
{

	return false;
}
