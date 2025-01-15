#include "pch.h"
#include "Goblin.h"
#include "Creature.h"
#include "Targeting.h"

Goblin::Goblin(string name, int hp, int atk, int arm, int speed):Monster(name, hp, atk, arm, speed)
{
	cout << "고블린 생성" << endl;
}

void Goblin::Act(vector<Creature*>& enemys, vector<Creature*>& friendlys)
{

	if (!IsAlive())
	{
		return;
	}
	Bite(enemys);

}

void Goblin::Bite(vector<Creature*>& enemys, vector<Creature*>& friendlys)
{
	cout << this->_name << "가 Bite 시전" << endl;
	int n = 0;
	Targeting* defaultTarget = new RandomTargeting();
	

	int damage = this->_atk;

	if ((*defaultTarget)(*this,enemys, friendlys))
		enemys[n]->Damaged(*this,damage);

	delete defaultTarget;
}
