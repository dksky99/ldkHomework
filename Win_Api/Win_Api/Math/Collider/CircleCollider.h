#pragma once
#include "Math/Collider/Collider.h"
class CircleCollider : public Collider,public enable_shared_from_this<CircleCollider>
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


	virtual bool IsCollision(const Vector& pos) override;
	virtual bool IsCollision(shared_ptr<CircleCollider> other)override;
	virtual bool IsCollision(shared_ptr<class RectCollider> other)override;


private:

	float _radius;

};

