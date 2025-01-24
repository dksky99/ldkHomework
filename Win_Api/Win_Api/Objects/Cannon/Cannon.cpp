#include "framework.h"

#include "Math/Collider/CircleCollider.h"
#include "Math/Collider/Line.h"
#include "Objects/Cannon/Barrel.h"
#include "Objects/Cannon/Ball.h"
#include "Cannon.h"

Cannon::Cannon()
{
	_speed = 10;

	_body = make_shared<CircleCollider>(WIN_CENTER, 50);
	
	_barrel = make_shared<Barrel>(_body);
	for (int i = 0;i < _poolCount;i++)
	{
		_balls.push_back(make_shared<Ball>());

	}
	
	
}

Cannon::~Cannon()
{
}

void Cannon::PostInitialize()
{
}

void Cannon::Update()
{
	_body->Update();
	_barrel->Update();
	for (auto ball : _balls)
	{

		ball->Update();
	}
	
	_delay += 0.1f;

	Move();
	Fire();
}

void Cannon::Render(HDC hdc)
{
	_barrel->Render(hdc);
	_body->Render(hdc);
	for (auto ball : _balls)
	{

		ball->Render(hdc);
	}
}

void Cannon::Move()
{

	if (GetKeyState('A') & 0x8000)
	{
		_body->SetCenter(_body->GetCenter() + Vector(-1, 0)*_speed);
		
	}
	if (GetKeyState('D') & 0x8000)
	{
		_body->SetCenter(_body->GetCenter() + Vector(+1, 0)*_speed);
	}

	
	if (GetKeyState('W') & 0x8000)
	{
		_barrel->SetAngle(_barrel->GetAngle() - 0.1f);
	}
	if (GetKeyState('S') & 0x8000)
	{
		_barrel->SetAngle(_barrel->GetAngle() + 0.1f);
	}
	

}

void Cannon::Fire()
{

	if (_delay < _attackSpeed)
		return;

	if (GetKeyState(VK_SPACE) & 0x8000)
	{
		auto iter = find_if(_balls.begin(), _balls.end(), [](shared_ptr<Ball> b) {return !(b->isActive);});
		if (iter == _balls.end())
			return;
		_delay = 0.0f;
		(*iter)->SetPos(_barrel->GetMuzzle());
		(*iter)->SetDir(_barrel->GetDir());
		(*iter)->isActive = true;

	}
}

