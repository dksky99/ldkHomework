#include "framework.h"

#include "Math/Collider/RectCollider.h"
#include "Math/Collider/CircleCollider.h"
#include "Objects/Arkanoid/Arkanoid_Ball.h"
#include "Objects/Arkanoid/Arkanoid_Wall.h"
#include "Arkanoid_Player.h"

Arkanoid_Player::Arkanoid_Player()
{
	isActive = true;
	_speed = 10;

	_body = make_shared<RectCollider>(WIN_CENTER+Vector(0,200), Vector(200, 30));
	
}

Arkanoid_Player::~Arkanoid_Player()
{
}

void Arkanoid_Player::Init()
{
	for (int i = 0;i < _poolCount;i++)
	{
		_balls.push_back(make_shared<Arkanoid_Ball>(shared_from_this()));

	}
	_balls[0]->isActive = true;
	_balls[0]->SetPos(GetFirePos());
}

void Arkanoid_Player::Update()
{

	for (auto ball : _balls)
	{

		ball->Update();
	}

	if (isActive == false)
		return;
	_body->Update();
	Move();
	Fire();

}

void Arkanoid_Player::Render(HDC hdc)
{

	for (auto ball : _balls)
	{

		ball->Render(hdc);
	}

	if (!isActive)
		return;
	_body->Render(hdc);
}

void Arkanoid_Player::Move()
{
	if (isActive == false)
		return;
	if (GetKeyState('A') & 0x8000)
	{
		_body->SetCenter(_body->GetCenter() + Vector(-1, 0) * _speed);

	}
	if (GetKeyState('D') & 0x8000)
	{
		_body->SetCenter(_body->GetCenter() + Vector(+1, 0) * _speed);
	}

}

void Arkanoid_Player::Fire()
{
	if (isActive == false)
		return;

	if (GetKeyState(VK_SPACE) & 0x8000)
	{
		auto iter = find_if(_balls.begin(), _balls.end(), [](shared_ptr<Arkanoid_Ball> ball) {return ball->isActive&&!ball->IsFired();});
			
		if (iter == _balls.end())
			return;

		(*iter)->SetPos(GetFirePos());
		(*iter)->SetDir(Vector::UP());
		

		

	}
}

Vector Arkanoid_Player::GetFirePos()
{
	Vector temp = _body->GetCenter() - Vector(0, _body->GetRect().y / 2+20);

	return temp;
}

bool Arkanoid_Player::IsCollision(shared_ptr<class Arkanoid_Ball> ball)
{
	
	if (_body->IsCollision(ball->GetCollider()))
	{
		if (ball->GetCollider()->GetCenter().x < _body->GetCenter().x)
			ball->DiffuseReflection(_body);
		else
			ball->RegularReflection(_body);

		return true;
	}


	return false;
}

void Arkanoid_Player::SetBallDeadEvent(function<void(void)> fn)
{
	for (auto ball : _balls)
	{

		ball->SetBallDead(fn);
	}
}

void Arkanoid_Player::ItemSkill()
{
   auto iter=find_if(_balls.begin(), _balls.end(), [](shared_ptr<Arkanoid_Ball> ball) {return(ball->isActive == false);});

   if (iter != _balls.end())
   {
	   (*iter)->isActive = true;
   }

}
