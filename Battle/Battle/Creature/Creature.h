#pragma once
#include "pch.h"






class Creature
{
public:
	Creature(string name, int hp, int atk,int arm, int speed, int teamNum);

	virtual void Act(vector<Creature*>& enemys, vector<Creature*>& friendlys) abstract;

	bool Update();
	void Attack(class Creature& victim,int dmg);
	void Damaged(Creature& attacker, int atk);
	bool IsAlive();
	bool TryTargeting(Creature* target);
	void HitLogging(Creature* attacker,int dmg);
	const unordered_map<Creature*, int>& GetHitRank();



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
	unordered_map<Creature*, int> hitLog;



};

