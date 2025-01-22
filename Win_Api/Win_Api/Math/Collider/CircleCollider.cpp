#include "framework.h"
#include "RectCollider.h"
#include "CircleCollider.h"

CircleCollider::CircleCollider(float x, float y, float radius):Collider(x,y),_radius(radius)
{

}

CircleCollider::CircleCollider(Vector v, float radius):Collider(v),_radius(radius)
{
}

CircleCollider::~CircleCollider()
{
}

void CircleCollider::Update()
{


}

void CircleCollider::Render(HDC hdc)
{


	float left = _center.x - _radius;
	float right = _center.x + _radius;
	float top = _center.y - _radius;
	float bottom = _center.y + _radius;


	SelectObject(hdc, _pens[_curPen]);

	Ellipse(hdc, left, top, right, bottom);

}

bool CircleCollider::IsCollision(const Vector& pos)
{
	Vector circleCenter = GetCenter();
	Vector direction = pos-circleCenter;

	

	return direction.Length()<_radius;
}

bool CircleCollider::IsCollision(shared_ptr<CircleCollider> other)
{

	Vector circleCenter1 = GetCenter();

	Vector circleCente2 = other->GetCenter();
	Vector direction = circleCenter1 - circleCente2;


	return direction.Length() < _radius + other->GetRadius();
}


bool CircleCollider::IsCollision(shared_ptr<RectCollider> other)
{

	float rad = GetRadius() + other->GetRect().Length()/2;
	float dist;

	//사각형 내부에 원의 중심이 있는지 확인.
	if (other->IsCollision(GetCenter()))
		return true;
	//사선방향에서의 접근
	if (IsCollision(Vector(other->Left(), other->Top())))
		return true;
	if (IsCollision(Vector(other->Left(), other->Bottom())))
		return true;
	if (IsCollision(Vector(other->Right(), other->Top())))
		return true;
	if (IsCollision(Vector(other->Right(), other->Bottom())))
		return true;
	//6 12 방향에서 접근

	if (other->Left() < GetCenter().x && other->Right() >GetCenter().x)
	{
		rad = GetRadius() + other->GetRect().y / 2;
		dist = GetCenter().y - other->GetCenter().y;
		if (dist < rad)
			return true;
	}
	//3 9 방향에서 접근
	if (other->Top() < GetCenter().y && other->Bottom() > GetCenter().y)
	{

		rad = GetRadius() + other->GetRect().x / 2;
		dist = GetCenter().x - other->GetCenter().x;
		if (dist < rad)
			return true;
	}

	return false;
}