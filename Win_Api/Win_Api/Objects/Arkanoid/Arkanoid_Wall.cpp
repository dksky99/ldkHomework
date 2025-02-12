#include "framework.h"
#include "Math/Collider/RectCollider.h"
#include "Math/Collider/CircleCollider.h"
#include "Objects/Arkanoid/Arkanoid_Ball.h"
#include "Objects/Arkanoid/Arkanoid_Item.h"
#include "Arkanoid_Wall.h"

Arkanoid_Wall::Arkanoid_Wall()
{
	isActive = true;

	_collider = make_shared<RectCollider>(WIN_CENTER, Vector(100,40));

	

}

Arkanoid_Wall::Arkanoid_Wall(Vector pos)
{
	isActive = true;

	_collider = make_shared<RectCollider>(pos, Vector(100, 40));


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

	if (isActive == false)
		return;
	_collider->Update();
	
}

void Arkanoid_Wall::Render(HDC hdc)
{


	if (isActive == false)
		return;
	_collider->Render(hdc);
}

bool Arkanoid_Wall::IsCollision(shared_ptr<class Arkanoid_Ball> ball)
{

	if (isActive == false)
		return false;
	if (_collider->IsCollision(ball->GetCollider()))
	{
		ItemLiberation();

		isActive = false;

		ball->BlockReflection(_collider);


		return true;
	}
	return false;
}

void Arkanoid_Wall::ItemLiberation()
{
	if (_item.lock() == nullptr)
		return;
	_item.lock()->ItemLiberation();
}

void Arkanoid_Wall::SetItem(shared_ptr<class Arkanoid_Item> item)
{
	_item = item;
	_item.lock()->SetPos(_collider->GetCenter());

}
