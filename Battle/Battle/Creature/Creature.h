#pragma once
#include<vector>
#include<unordered_map>
#include "Targeting.h"


class StateAbnormality_Aggro
{
public:
	void SetTarget(class Creature* target,int duration)
	{
		_duration = duration;
		_targeting = new AggroTargeting();
		_targeting->target = target;
	}
	Targeting* GetTargeting() 
	{ 
		return _targeting;
	
	}
	

private:

	int _duration;
	AggroTargeting* _targeting;


};



class Creature
{
public:
	Creature(string name, int hp, int atk,int arm, int speed, int teamNum);

	virtual void Act(vector<Creature*>& enemys, vector<Creature*>& friendlys) abstract;

	bool Update();
	Creature* TargetChoice(vector<Creature*>& enemys, vector<Creature*>& friendlys, function<Creature* (Creature* owner,vector<Creature*>, vector<Creature*>)>);
	void Attack(class Creature& victim,int dmg);
	void Damaged(Creature& attacker, int atk);
	bool IsAlive();
	bool TryTargeting(Creature* target);
	void HitLogging(Creature* attacker,int dmg);
	const unordered_map<Creature*, int>& GetHitRank();



	void PrintCreature();


	int GetHp() { return _hp; }


protected:
	//이름
	string _name;
	//체력
	int _hp;
	//공격력
	int _atk;
	//방어력
	int _arm;
	//행동속도
	int _speed;
	const int _defaultActionGuage=100;
	int _actionGuage;

	unsigned char _state;

	int _teamNum;
	unordered_map<Creature*, int> hitLog;



};

