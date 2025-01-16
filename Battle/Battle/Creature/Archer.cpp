#include "pch.h"
#include "Targeting.h"
#include "Archer.h"

Archer::Archer(string name, int hp, int atk, int arm, int speed) :Player(name, hp, atk, arm, speed)
{
	cout << "�ü� ����." << endl;
}

void Archer::Act(vector<Creature*>& enemys, vector<Creature*>& friendlys)
{
	if (!IsAlive())
	{
		return;
	}
	int n = rand() % 3;
	switch (n)
	{
	case 0:
	case 1:
		Multishot(enemys, friendlys);
		break;
	case 2:
	default:
		Sniping(enemys, friendlys);
		break;

	}
}

void Archer::Multishot(vector<Creature*>& enemys, vector<Creature*>& friendlys)
{
	cout << this->_name << "�� Multishot ����" << endl;
	int n = 0;
	for (int i = 0; i < 5; i++)
	{

		Targeting* defaultTarget = new RandomTargeting();


		int damage = this->_atk * 3;
		Creature* target = (*defaultTarget)(*this, enemys, friendlys);
		if (target)
			target->Damaged(*this, damage);

		delete defaultTarget;

	}

}

void Archer::Sniping(vector<Creature*>& enemys, vector<Creature*>& friendlys)
{

	cout << this->_name << "�� Sniping ����" << endl;


	Targeting* defaultTarget = new RandomTargeting();
	

	int damage = this->_atk * 6;
	Creature* target = (*defaultTarget)(*this, enemys, friendlys);
	if (target)
		target->Damaged(*this, damage);

	delete defaultTarget;

}
