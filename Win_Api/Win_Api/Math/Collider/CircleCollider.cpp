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
	
	return other->IsCollision(shared_from_this());
}