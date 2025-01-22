#pragma once
#include "Math/Collider/Collider.h"
class CircleCollider : public Collider
{
public:

	CircleCollider(float x,float y,float radius);
	CircleCollider(Vector v,float radius);
	~CircleCollider();

	// Collider을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	void SetRadius(float radius) { _radius = radius; }

	float GetRadius() { return _radius; }


	bool IsCollision(const Vector& pos);
	bool IsCollision(shared_ptr<CircleCollider> other);
	bool IsCollision(shared_ptr<class RectCollider> other);


private:

	float _radius;

};

