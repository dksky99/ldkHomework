#pragma once
#include "Objects/Object.h"
class Barrel : public Object
{
public:

	Barrel(shared_ptr<class CircleCollider> cannon);
	~Barrel();

	// Object을(를) 통해 상속됨
	void Update() override;

	void Render(HDC hdc) override;

	void SetDirection(Vector dir) { _barrelDir = dir.NormalVector(); }
	void SetAngle(float angle) { _angle = angle; }

	Vector GetDir() { return _barrelDir; }
	float GetAngle(){ return _angle; }

	Vector GetMuzzle() { return _barrel->end; }
	

private:

	Vector _barrelDir;
	float _barrelLength;

	float _angle;

	shared_ptr<class Line> _barrel;
	weak_ptr<class CircleCollider> _cannonBody;
};

