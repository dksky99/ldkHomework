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
	//가속
	//SinMove();
	//GravityMove();
	//GuideMove();
	
	BasicMove();
	_circle->Update();

	//화면 밖으로 나가는 예외처리
	//if (_circle->GetCenter().x > WIN_WIDTH || _circle->GetCenter().x <0 || _circle->GetCenter().y>WIN_HEIGHT || _circle->GetCenter().y < 0)
	//	isActive = false;

	//정반사. 방향백터의 x나 y부호만 반대로 변경. 
	Vector center = _circle->GetCenter();
	if (center.x<0 || center.x>WIN_WIDTH)
		_ballDir.x *= -1;
	if (center.y<0 || center.y>WIN_HEIGHT)
		_ballDir.y *= -1;


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

void Ball::GuideMove()
{
	Vector guided = mousePos - _circle->GetCenter();

	//볼과 타겟의 방향과 자신의 기존 진행방향을 외적해 +면 반시계방향으로 조금씩 회전하고
	//-면 시계방향으로 조금씩 회전, 외적한 절대값이 0에 가깝다면 진행방향이 평행에 가까우니 
	// 그대로 진행.
	float cross = _ballDir.Cross(guided);
	if (abs(cross) < 0.01)
	{

	}
	else if(cross<0.0f)
	{
		_ballDir=_ballDir.Rotate(-0.01);
	}
	else 
	{
		_ballDir = _ballDir.Rotate(0.01);
	}


}

