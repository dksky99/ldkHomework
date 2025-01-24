#include "framework.h"
#include "Line.h"

//�ݽð�������� ���� ��� �ð�������ΰ��� ����
//�� ���� ������ ���� ���� �ٽ� 
Line::Line(Vector start, Vector end): start(start),end(end)
{
	_pen = CreatePen(1, 3, GREEN);
}

Line::~Line()
{
	DeleteObject(_pen);
}

void Line::Update()
{
}

void Line::Render(HDC hdc)
{
	SelectObject(hdc, _pens[_curPen]);
	MoveToEx(hdc, start.x, start.y, nullptr);

	LineTo(hdc, end.x, end.y);

}

Line::HitResult Line::IsCollision(shared_ptr<Line> other)
{
	// ������ ���� �� ���� �糡�� �ڽ��� �ݴ��� �ִ��� 
	Vector v1Dir = end - start;
	Vector a1 = other->start - start;
	Vector b1 = other->end - start;

	bool v1_between = v1Dir.IsBetween(a1, b1);

	Vector v2Dir = other->end - other->start;
	Vector a2 = start - other->start;
	Vector b2 = end - other->start;

	bool v2_between = v2Dir.IsBetween(a2, b2);


	HitResult hit;
	hit.isCollision= v1_between&&v2_between;
	if (hit.isCollision == false)
		return hit;

	float leftB = abs(v1Dir.Cross(a1));
	float rightB = abs(v1Dir.Cross(b1));

	float f = leftB / (leftB + rightB);

	hit.hitPoint = LERP(other->start, other->end, f);

	return hit;


	

	

}


bool Line::CollisionPoint(shared_ptr<Line> other ,Vector& ret)
{
	
	

	//�и�
	float denom = (end.x - start.x) * (other->end.y - other->start.y) - (end.y - start.y) * (other->end.x - other->start.x);

	//����
	float num1 = (other->start.x - start.x) * (other->end.y - other->start.y) - (other->start.y - start.y) * (other->end.x - other->start.x);
	//float num2 = (other->start.x - start.x) * (end.y - start.y) - (other->start.y - start.y) * (end.x - start.x);

	//���?
	float t = num1 / denom;

	// ������ ���
	float ix = start.x + t * (end.x - start.x);
	float iy = start.y + t * (end.y - start.y);
	ret.x = ix;
	ret.y = iy;

	return true;


	//float t1=(end.y-start.y)/

}
