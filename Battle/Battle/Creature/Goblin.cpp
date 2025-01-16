#include "pch.h"
#include "Creature.h"
#include "Targeting.h"
#include "Goblin.h"

Goblin::Goblin(string name, int hp, int atk, int arm, int speed):Monster(name, hp, atk, arm, speed)
{
	cout << "��� ����" << endl;
}

void Goblin::Act(vector<Creature*>& enemys, vector<Creature*>& friendlys)
{

	if (!IsAlive())
	{
		return;
	}
	Bite(enemys,friendlys);

}

void Goblin::Bite(vector<Creature*>& enemys, vector<Creature*>& friendlys)
{
	cout << this->_name << "�� Bite ����" << endl;
	int n = 0;
	Targeting* defaultTarget = new RandomTargeting();
	

	int damage = this->_atk;

	Creature* target = (*defaultTarget)(*this, enemys, friendlys);
	if (target)
		target->Damaged(*this, damage);

	delete defaultTarget;
}
