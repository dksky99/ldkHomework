#pragma once
#include "Objects/Object.h"

class Arkanoid_Player : public Object,public enable_shared_from_this<Arkanoid_Player>
{
public:
	Arkanoid_Player();
	~Arkanoid_Player();
	void Init();


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

	void ItemSkill();

private:

	shared_ptr<class RectCollider> _body;
	vector<shared_ptr<class Arkanoid_Ball>> _balls;


	UINT _poolCount = 10;
	float _speed;

};

