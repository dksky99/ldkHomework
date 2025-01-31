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

	//���� ó��. ���� �簢�� ���� �� �Ÿ��� ���� �������� ��ģ���̺��� �� �߽��� �Ÿ��� �� �ִٸ� ������ �ƴ�.
	float length = dir.Length();
	float rectHalfLength = _halfSize.Length();
	float circleRadius = other->GetRadius();

	if (length > rectHalfLength + other->GetRadius())
		return false;

	//x�� ���� : x�࿡ �� �߽��� �Ÿ��� ���������� 
	float lengthx = abs(rightV.Dot(dir));
	//x���� �ִ� ����
	if (lengthx > _halfSize.x + circleRadius)
		return false;

	//y�� ���� : y�࿡ �� �߽��� �Ÿ��� ����.
	float lengthy = abs(upV.Dot(dir));

	//y���� ������ ���̰� y�� �ִ���̺��� ũ�� �浹 x
	if (lengthy > _halfSize.y + circleRadius)
		return false;

	return true;
	
	

	
}