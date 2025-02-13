#include "framework.h"
#include "Math/Collider/CircleCollider.h"
#include "Math/Collider/RectCollider.h"
#include "Objects/Arkanoid/Arkanoid_Player.h"
#include "Arkanoid_Item.h"

Arkanoid_Item::Arkanoid_Item()
{
	_body = make_shared<CircleCollider>(Vector(), 5.0f);
	isActive = true;
}

Arkanoid_Item::~Arkanoid_Item()
{
}

void Arkanoid_Item::Update()
{
	if (isActive == false)
		return;
	if (isLiberation)
	{
		Drop();
	}

	_body->Update();

	

}

void Arkanoid_Item::Render(HDC hdc)
{
	if (isActive == false)
		return;
	_body->Render(hdc);
}

void Arkanoid_Item::Drop()
{
	SetPos(GetPos() + _dir * _speed);

}

Vector Arkanoid_Item::GetPos()
{
	 return _body->GetCenter(); 
}

void Arkanoid_Item::SetPos(Vector dir)
{
	_body->SetCenter(dir);
}

bool Arkanoid_Item::IsCollision(shared_ptr<class Arkanoid_Player> player)
{
	if (isActive == false)
		return;
	bool result=player->GetCollider()->IsCollision(_body);
	if (result)
	{
		isActive = false;
		_itemSkill();
	}
	return result;
}

void Arkanoid_Item::SetItemSkill(function<void(void)> fn)
{
	_itemSkill = fn;
}
