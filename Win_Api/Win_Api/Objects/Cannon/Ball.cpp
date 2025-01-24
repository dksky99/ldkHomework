#include "framework.h"
#include "Math/Collider/CircleCollider.h"
#include "Ball.h"

Ball::Ball()
{
	_circle = make_shared<CircleCollider>(1000, 1000, 10);
	isActive = false;
}

Ball::~Ball()
{
}

void Ball::Update()
{
	if (!isActive)
		return;
	//°¡¼Ó
	_theta += 0.05f;
	_gravityDir += _gravityDir;
	Vector a = Vector(0,sinf(_theta));
	AddForce(a*2);
	AddForce(_ballDir*_ballSpeed);
	AddForce(_gravityDir);
	_circle->Update();

	if (_circle->GetCenter().x > WIN_WIDTH || _circle->GetCenter().x <0 || _circle->GetCenter().y>WIN_HEIGHT || _circle->GetCenter().y < 0)
		isActive = false;
}

void Ball::Render(HDC hdc)
{
	if (!isActive)
		return;
	_circle->Render(hdc);
}

void Ball::AddForce(Vector v)
{
	_circle->SetCenter(_circle->GetCenter() + v);
}
