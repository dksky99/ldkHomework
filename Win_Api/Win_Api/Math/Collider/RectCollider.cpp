#include "framework.h"
#include "CircleCollider.h"

#include "RectCollider.h"

RectCollider::RectCollider(float x, float y, int width, int height):Collider(x,y), _halfSize(width/2,height/2)
{
}

RectCollider::RectCollider(Vector center, Vector size):Collider(center),_halfSize(size.x/2,size.y/2)
{
}

RectCollider::~RectCollider()
{

}

void RectCollider::Update()
{
}

void RectCollider::Render(HDC hdc)
{
	float left = _center.x - _halfSize.x;
	float right = _center.x + _halfSize.x;
	float top = _center.y - _halfSize.y;
	float bottom = _center.y + _halfSize.y;


	SelectObject(hdc, _pens[_curPen]);

	Rectangle(hdc, left,top,right,bottom);
}

bool RectCollider::IsCollision(const Vector& pos)
{
	bool Vetical = Left() < pos.x && pos.x < Right();
	bool Horizontal = Top() < pos.y && pos.y < Bottom();




	return Vetical && Horizontal;
 
}

bool RectCollider::IsCollision(shared_ptr<RectCollider> other)
{
	bool Vetical = Left() < other->Right()&&  other->Left() < Right();
	bool Horizontal = Top() < other->Bottom() && other->Top() < Bottom();

	if (other->Left() > Right())
		return false;
	if (other->Right() < Left())
		return false;

	if (other->Top() > Bottom())
		return false;
	if (other->Bottom() < Top())
		return false;

	

	return true;
}

bool RectCollider::RectCollider::IsCollision(shared_ptr<CircleCollider> other)
{

	
	float rad = other->GetRadius() + _halfSize.Length();
	float dist;

	//사각형 내부에 원의 중심이 있는지 확인.
	if (IsCollision(other->GetCenter()))
		return true;
	//사선방향에서의 접근
	if (other->IsCollision(Vector(Left(), Top())))
		return true;
	if (other->IsCollision(Vector(Left(), Bottom())))
		return true;
	if (other->IsCollision(Vector(Right(), Top())))
		return true;
	if (other->IsCollision(Vector(Right(), Bottom())))
		return true;
	//6 12 방향에서 접근
	
	if (Left() < other->GetCenter().x&&Right()>other->GetCenter().x)
	{
		rad = other->GetRadius() + _halfSize.y;
		dist = other->GetCenter().y - GetCenter().y;
		if (dist < rad)
			return true;
	}
	//3 9 방향에서 접근
	if (Top() < other->GetCenter().y && Bottom() > other->GetCenter().y)
	{

		rad = other->GetRadius() + _halfSize.x;
		dist = other->GetCenter().x - GetCenter().x;
		if (dist < rad)
			return true;
	}

	return false;

	
}