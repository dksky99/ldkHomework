#pragma once
#include "Objects/Object.h"

class Arkanoid_Player : public Object
{
public:
	Arkanoid_Player();
	~Arkanoid_Player();


	// Object을(를) 통해 상속됨
	virtual void Update() override;

	virtual void Render(HDC hdc) override;

	void Move();
	void Fire();

	Vector GetFirePos();

	shared_ptr<class RectCollider> GetCollider() { return _body; }

	bool IsCollision(shared_ptr<class Arkanoid_Ball> ball);
	vector<shared_ptr<class Arkanoid_Ball>> GetBalls() { return _balls; }

	void SetBallDeadEvent(function<void(void)> fn);


private:

	shared_ptr<class RectCollider> _body;
	vector<shared_ptr<class Arkanoid_Ball>> _balls;


	UINT _poolCount = 10;
	float _speed;

};

