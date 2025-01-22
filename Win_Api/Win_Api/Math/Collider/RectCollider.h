#pragma once
#include "Math/Collider/Collider.h"
class RectCollider : public Collider
{
public:
	RectCollider(float x, float y, int width, int height);
	RectCollider(Vector center, Vector size);
	~RectCollider();

	// Collider을(를) 통해 상속됨
	void Update() override;
	void Render(HDC hdc) override;

	void SetRect(float w, float h) { _halfSize.x = w / 2;_halfSize.y = h / 2; }
	Vector GetRect() { return Vector(_halfSize.x * 2, _halfSize.y * 2); }

	float Left() {return  _center.x - _halfSize.x;}
	float Right(){return   _center.x + _halfSize.x;}
	float Top()  {return _center.y - _halfSize.y;  }
	float Bottom() { return _center.y + _halfSize.y; }



	bool IsCollision(const Vector& pos);
	bool IsCollision(shared_ptr<RectCollider> other);
	bool IsCollision(shared_ptr<class CircleCollider> other);

private:

	Vector _halfSize;


};

