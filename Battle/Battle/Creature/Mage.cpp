#include "pch.h"
#include "Mage.h"
#include "Creature.h"

Mage::Mage(string name, int hp, int atk, int arm, int speed):Player(name, hp, atk, arm, speed)
{
	cout << "마법사 생성" << endl;
}

void Mage::Act(Creature* enemys[], int enemyCount, Creature* friendlys[], int friendCount)
{
	if (!IsAlive())
	{
		return;
	}
	int n = rand() % 2;
	switch (n)
	{
	case 0 :
		LightningPierce(enemys,enemyCount);
		break;
	case 1:
	default :
		FireStorm(enemys,enemyCount);
		break;

	}
}

void Mage::LightningPierce(Creature* enemys[], int enemyCount)
{
	cout << _name << "가 번개 화살을 시전" << endl;
	int n = 0;
	do
	{
		n = rand() % enemyCount;
	} while (!Targeting(enemys[n]) && CheckEnemysAlive((Creature**)enemys, enemyCount));

	int damage = this->_atk * 10;
	if (Targeting(enemys[n]))
		enemys[n]->Damaged(damage);
}

void Mage::FireStorm(Creature* enemys[], int enemyCount)
{
	cout<<_name << "가 파이어 스톰을 시전" << endl;
	int damage = this->_atk*2;
	for (int i = 0; i < enemyCount; i++)
	{
		if(Targeting(enemys[i]))
			enemys[i]->Damaged(damage);
	}
}
