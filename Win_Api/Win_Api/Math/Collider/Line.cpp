#include "framework.h"
#include "Line.h"

//반시계방향으로 가면 양수 시계방향으로가면 음수
//두 선을 외적해 나온 선을 다시 
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

bool Line::IsCollision(shared_ptr<Line> other)
{
	// 방향을 따라서 그 선의 양끝이 자신의 반대편에 있는지 
	Vector v1Dir = end - start;
	Vector a1 = other->start - start;
	Vector b1 = other->end - start;

	bool v1_between = v1Dir.IsBetween(a1, b1);

	Vector v2Dir = other->end - other->start;
	Vector a2 = start - other->start;
	Vector b2 = end - other->start;

	bool v2_between = v2Dir.IsBetween(a2, b2);

	return v1_between&&v2_between;


	

	

}


bool Line::CollisionPoint(shared_ptr<Line> other ,Vector& ret)
{
	if (!IsCollision(other))
		return false;

	//분모
	float denom = (end.x - start.x) * (other->end.y - other->start.y) - (end.y - start.y) * (other->end.x - other->start.x);

	//분자
	float num1 = (other->start.x - start.x) * (other->end.y - other->start.y) - (other->start.y - start.y) * (other->end.x - other->start.x);
	//float num2 = (other->start.x - start.x) * (end.y - start.y) - (other->start.y - start.y) * (end.x - start.x);

	//계수?
	float t = num1 / denom;

	// 교차점 계산
	float ix = start.x + t * (end.x - start.x);
	float iy = start.y + t * (end.y - start.y);
	ret.x = ix;
	ret.y = iy;

	return true;


	//float t1=(end.y-start.y)/

}
