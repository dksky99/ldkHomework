#include "pch.h"
#include "Targeting.h"

#include "Creature.h"


Creature::Creature(string name, int hp, int atk, int arm, int speed,int teamNum):_name(name),_hp(hp),_atk(atk),_arm(arm), _speed(speed),_actionGuage(100),_teamNum(teamNum)
{
	cout << name<<"가 생성 완료됬습니다." << endl;

}


bool Creature::Update()
{
	_actionGuage -= _speed;

	if (_actionGuage < 0)
	{
		_actionGuage += _defaultActionGuage;
		return true;
	}
	return false;
}


void Creature::Attack(shared_ptr<Creature> victim, int dmg)
{
	victim->Damaged(shared_from_this(), dmg);
}

void Creature::Damaged(shared_ptr<Creature> attacker, int atk)
{
	int dmg = atk - _arm;

	
	if (dmg < 1)
		dmg = 1;
	_hp -= dmg;
	HitLogging(attacker, dmg);
	if (_hp <= 0)
	{
		_hp = 0;
	}
	cout<<_name<<"가 " << dmg << "만큼의 피해를 입었습니다. 잔여 HP :" << _hp << endl;


}

bool Creature::IsAlive()
{
	return _hp>0;
}

bool Creature::TryTargeting(shared_ptr<Creature> target)
{
	if (target == nullptr)
	{
		return false;
	}

	if (target->IsAlive())
	{
		return true;
	}

	return false;
}

void Creature::HitLogging(shared_ptr<Creature> attacker, int dmg)
{
	
	unordered_map<weak_ptr<Creature>,int>::iterator result = find_if(hitLog.begin(), hitLog.end(), [attacker](std::pair<weak_ptr<Creature>, int> a) {return attacker == a.first.lock();});
	if (result!=hitLog.end())
	{
		result->second += dmg;
	}
	else
	{
		pair<weak_ptr<Creature>,int> a=make_pair(attacker, dmg);
		hitLog.insert(a);

	}
}

const unordered_map<weak_ptr<Creature>, int>& Creature::GetHitRank()
{
	return hitLog;
}

void Creature::PrintCreature()
{
	cout << "이름 : " << _name << endl;
	cout << "Hp : " << _hp << endl;
	cout << "Atk : " << _atk << endl;
	cout << "Arm : " << _arm << endl;
	cout << "Speed : " << _speed<< endl;
}

