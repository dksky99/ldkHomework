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
	SinMove();
	//GravityMove();
	BasicMove();
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

void Ball::AddVector(Vector v)
{
	_circle->SetCenter(_circle->GetCenter() + v);
}

void Ball::GravityMove()
{
	if (!isActive)
		return;

	_gravityDir += _gravityWeight;
	AddVector(_gravityDir);

}

void Ball::SinMove()
{

	if (!isActive)
		return;
	Vector normal = _ballDir.NormalVector();
	normal=normal.Rotate(90);
	float a = 2.0f;
	
	float offset = sinf(_theta)*a;
	_theta += 0.05f;

	
	 normal=(normal * offset);

	AddVector(normal);

}

void Ball::BasicMove()
{
	if (!isActive)
		return;
	AddVector(_ballDir * _ballSpeed);
}

