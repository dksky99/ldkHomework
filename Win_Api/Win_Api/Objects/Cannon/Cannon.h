#pragma once

#include "Objects/Object.h"
#include "Scene/CannonScene.h"

class Cannon : public Object, public enable_shared_from_this<Cannon>
{
public:

	Cannon();

	~Cannon();

	//후처리 초기화
	void PostInitialize();

	// Object을(를) 통해 상속됨
	virtual void Update() override;

	virtual void Render(HDC hdc) override;

	void Move();
	void Fire();
	shared_ptr<class CircleCollider> GetCollider() { return _body; }
	void TurnFinish() { _myTurn = false; }
	void TurnStart() { _myTurn = true; }

	void SetTurnFinish(function<void(void)> fn) { turnfinish = fn; }

	bool IsCollision(shared_ptr<class Ball> ball);
	vector<shared_ptr<class Ball>> GetBalls() { return _balls; }
private:

	float GetMouseAngle();


private:

	shared_ptr<class CircleCollider> _body;
	shared_ptr<class Barrel> _barrel;
	//오브젝트 풀링(번식지를 만드는것)
	//할당 해제를 최소화하기 위해 미리 만들어놓고 나중에 쓸일이없을떄 지우는것.
	vector<shared_ptr<class Ball>> _balls;
	UINT _poolCount = 10;
	Vector _ballDir;
	float _speed;

	float ballangle;

	float _delay=0.0f;

	const float _attackSpeed = 3.0f;
	
	bool _myTurn=false;

	//턴종료하기위해 호출
	function<void(void)> turnfinish;
};

