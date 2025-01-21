#pragma once
#include "pch.h"






class Creature : public enable_shared_from_this<Creature>
{
public:
	Creature(string name, int hp, int atk,int arm, int speed, int teamNum);

	virtual void Act(vector<shared_ptr<Creature>> enemys, vector<shared_ptr<Creature>> friendlys) abstract;

	bool Update();
	void Attack(shared_ptr<Creature> victim,int dmg);
	void Damaged(shared_ptr<Creature> attacker, int atk);
	bool IsAlive();
	bool TryTargeting(shared_ptr<Creature> target);
	void HitLogging(shared_ptr<Creature> attacker,int dmg);
	const unordered_map<weak_ptr<Creature>, int>& GetHitRank();



	void PrintCreature();


	int GetHp() { return _hp; }
	const string& GetName() { return _name; }


protected:
	//�̸�
	string _name;
	//ü��
	int _hp;
	//���ݷ�
	int _atk;
	//����
	int _arm;
	//�ൿ�ӵ�
	int _speed;
	const int _defaultActionGuage=100;
	int _actionGuage;


	int _teamNum;
	unordered_map<weak_ptr<Creature>, int> hitLog;



};

