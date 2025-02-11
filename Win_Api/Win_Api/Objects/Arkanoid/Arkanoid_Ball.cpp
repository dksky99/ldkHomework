#include "framework.h"
#include "Math/Collider/CircleCollider.h"
#include "Math/Collider/RectCollider.h"
#include "Arkanoid_Ball.h"

Arkanoid_Ball::Arkanoid_Ball()
{
	_circle = make_shared<CircleCollider>(1000, 1000, 10);
	isActive = false;
}

Arkanoid_Ball::~Arkanoid_Ball()
{
}

void Arkanoid_Ball::Update()
{
	if (!isActive)
		return;

	BasicMove();
	_circle->Update();

	//화면 밖으로 나가는 예외처리
	//if (_circle->GetCenter().x > WIN_WIDTH || _circle->GetCenter().x <0 || _circle->GetCenter().y>WIN_HEIGHT || _circle->GetCenter().y < 0)
	//	isActive = false;

	//정반사. 방향백터의 x나 y부호만 반대로 변경. 

	CheckWall();

}

void Arkanoid_Ball::Render(HDC hdc)
{
	if (!isActive)
		return;
	_circle->Render(hdc);
}

void Arkanoid_Ball::AddVector(Vector v)
{
	_circle->SetCenter(_circle->GetCenter() + v);
}

void Arkanoid_Ball::SetPos(Vector pos) 
{
	_circle->SetCenter(pos); 
}

void Arkanoid_Ball::BasicMove()
{
	if (!isActive)
		return;
	AddVector(_ballDir * _ballSpeed);
}

void Arkanoid_Ball::CheckWall()
{
	
	Vector center = _circle->GetCenter();
	if (center.x<0 || center.x>WIN_WIDTH)
		_ballDir.x *= -1;
	if (center.y<0 )
		_ballDir.y *= -1;
	if (center.y > WIN_HEIGHT)
	{
		BallDead();
	}
}

void Arkanoid_Ball::BlockReflection(shared_ptr<class RectCollider> other)
{
	Vector temp = _ballDir;
	Vector center = _circle->GetCenter();
	if (center.x<other->Left() || center.x>other->Right())
		temp.x *= -1;
	if (center.y > other->Bottom() || center.y < other->Top())
		temp.y *= -1;

	temp.Noramlize();
	_ballDir = temp;
}

void Arkanoid_Ball::RegularReflection(shared_ptr<RectCollider> other)
{
	
	Vector temp ;

	Vector center = _circle->GetCenter();
	if (center.x<other->Left() || center.x>other->Right())
	{

		temp = _ballDir;
		temp.x *= -1;
	}
	else if ( center.y < other->Top())
	{
		//기존 방향의 부호 확인
		float x = _ballDir.x>0?1:-1;
		float y = _ballDir.y > 0 ? 1 : -1;
		_circle->SetCenter(center.x, other->Top() - _circle->GetRadius());
		_circle->SetGreen();
		//공과 플레이어의 방향
		temp = other->GetCenter() - _circle->GetCenter();
		//부호는 기존대로 방향은 공과 플레이어의 방향대로.
		temp.x = abs(temp.x) * x;
		temp.y = abs(temp.y) * y;

	    //y진행방향만 역전.
		temp.y *= -1;
	}
	else
	{
		temp = Vector::Down();
	}

	temp.Noramlize();
	_ballDir = temp;

}

void Arkanoid_Ball::DiffuseReflection(shared_ptr<RectCollider> other)
{
	Vector temp = other->GetCenter() - _circle->GetCenter();

	Vector center = _circle->GetCenter();
	if (center.x<other->Left() || center.x>other->Right())
	{
		temp = _ballDir;
		temp.x *= -1;
	}
	else if (center.y < other->Top())
	{
		float x = _ballDir.x > 0 ? 1 : -1;
		float y = _ballDir.y > 0 ? 1 : -1;
		_circle->SetCenter(center.x, other->Top() - _circle->GetRadius());

		_circle->SetRed();
		temp = other->GetCenter() - _circle->GetCenter();
		temp.x = abs(temp.x) * x;
		temp.y = abs(temp.y) * y;

		//역반사니 거꾸로튕겨나가도록
		temp.y *= -1;
		temp.x *= -1;
	}
	else
	{
		temp = Vector::Down();
	}


	temp.Noramlize();
	_ballDir = temp;
}

void Arkanoid_Ball::BallDead()
{
	isActive = false;
	ballDead();
}
