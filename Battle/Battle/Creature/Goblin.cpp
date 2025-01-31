#include "pch.h"
#include "Creature.h"
#include "Targeting.h"
#include "Goblin.h"

Goblin::Goblin(string name, int hp, int atk, int arm, int speed):Monster(name, hp, atk, arm, speed)
{
	cout << "고블린 생성" << endl;
}

void Goblin::Act(vector<shared_ptr<Creature>>& enemys, vector<shared_ptr<Creature>>& friendlys) 
{

	if (!IsAlive())
	{
		return;
	}
	Bite(enemys,friendlys);

}

void Goblin::Bite(vector<shared_ptr<Creature>>& enemys, vector<shared_ptr<Creature>>& friendlys) 

{
	cout << this->_name << "가 Bite 시전" << endl;
	int n = 0;
	shared_ptr<Targeting> defaultTarget = make_shared<RandomTargeting>();
	
	int damage = this->_atk;

	shared_ptr<Creature> target = (*defaultTarget)(shared_from_this(), enemys, friendlys);
	if (target)
		target->Damaged(shared_from_this(), damage);

}
