#include "framework.h"
#include "CircleCollider.h"

#include "RectCollider.h"

RectCollider::RectCollider(float x, float y, int width, int height):Collider(x,y), _halfSize(width/2,height/2)
{

	_type = ColType::Rect;
}

RectCollider::RectCollider(Vector center, Vector size):Collider(center),_halfSize(size.x/2,size.y/2)
{
	_type = ColType::Rect;
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
	Vector dir = other->GetCenter() - GetCenter();
	Vector rightV = Vector(1, 0);
	Vector upV = Vector(0, 1);

	//예외 처리. 만약 사각의 가장 긴 거리와 원의 반지름을 합친길이보다 두 중심의 거리가 더 멀다면 무조건 아님.
	float length = dir.Length();
	float rectHalfLength = _halfSize.Length();
	float circleRadius = other->GetRadius();

	if (length > rectHalfLength + other->GetRadius())
		return false;

	//x축 내적 : x축에 두 중심의 거리를 투영했을때 
	float lengthx = abs(rightV.Dot(dir));
	//x축의 최대 길이
	if (lengthx > _halfSize.x + circleRadius)
		return false;

	//y축 내적 : y축에 두 중심의 거리를 투영.
	float lengthy = abs(upV.Dot(dir));

	//y축의 내적의 길이가 y축 최대길이보다 크면 충돌 x
	if (lengthy > _halfSize.y + circleRadius)
		return false;

	return true;
	
	

	
}