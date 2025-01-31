#pragma once

#include "Objects/Object.h"
#include "Scene/CannonScene.h"

class Cannon : public Object, public enable_shared_from_this<Cannon>
{
public:

	Cannon();

	~Cannon();

	//��ó�� �ʱ�ȭ
	void PostInitialize();

	// Object��(��) ���� ��ӵ�
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
	//������Ʈ Ǯ��(�������� ����°�)
	//�Ҵ� ������ �ּ�ȭ�ϱ� ���� �̸� �������� ���߿� �����̾����� ����°�.
	vector<shared_ptr<class Ball>> _balls;
	UINT _poolCount = 10;
	Vector _ballDir;
	float _speed;

	float ballangle;

	float _delay=0.0f;

	const float _attackSpeed = 3.0f;
	
	bool _myTurn=false;

	//�������ϱ����� ȣ��
	function<void(void)> turnfinish;
};

