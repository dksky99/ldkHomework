#include "pch.h"
#include "Targeting.h"
#include "Creature.h"
#include "Mage.h"

Mage::Mage(string name, int hp, int atk, int arm, int speed):Player(name, hp, atk, arm, speed)
{
	cout << "마법사 생성" << endl;
}

void Mage::Act(vector<Creature*>& enemys, vector<Creature*>& friendlys)
{
	if (!IsAlive())
	{
		return;
	}
	int n = rand() % 2;
	switch (n)
	{
	case 0 :
		LightningPierce(enemys, friendlys);
		break;
	case 1:
	default :
		FireStorm(enemys, friendlys);
		break;

	}
}

void Mage::LightningPierce(vector<Creature*>& enemys, vector<Creature*>& friendlys)
{
	cout << _name << "가 번개 화살을 시전" << endl;

	int n = 0;
	Targeting* defaultTarget = new RandomTargeting();


	int damage = this->_atk*10;

	Creature* target = (*defaultTarget)(*this, enemys, friendlys);
	if (target)
		target->Damaged(*this, damage);

	delete defaultTarget;
}

void Mage::FireStorm(vector<Creature*>& enemys, vector<Creature*>& friendlys)
{
	cout<<_name << "가 파이어 스톰을 시전" << endl;
	int damage = this->_atk*2;
	for (int i = 0; i < enemys.size(); i++)
	{
		if(enemys[i]->IsAlive())
			enemys[i]->Damaged(*this,damage);
	}
}
