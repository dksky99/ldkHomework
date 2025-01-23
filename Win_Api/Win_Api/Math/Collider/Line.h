#pragma once
#include "Collider.h"

class Line :public Collider
{
public:
	Line(Vector start, Vector end) ;
	~Line();

	// Collider을(를) 통해 상속됨
	void Update() override;

	void Render(HDC hdc) override;

	bool IsCollision(shared_ptr<Line> other);

	bool CollisionPoint(shared_ptr<Line> other, Vector& ret);
public:
	Vector start;
	Vector end;

private:
	HPEN _pen;



};

