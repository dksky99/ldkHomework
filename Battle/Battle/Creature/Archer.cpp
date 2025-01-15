#include "pch.h"
#include "Archer.h"

Archer::Archer(string name, int hp, int atk, int arm, int speed) :Player(name, hp, atk, arm, speed)
{
	cout << "궁수 생성." << endl;
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
		Multishot(enemys, enemyCount);
		break;
	case 2:
	default:
		Sniping(enemys, enemyCount);
		break;

	}
}

void Archer::Multishot(Creature* enemys[], int enemyCount)
{
	cout << this->_name << "가 Multishot 시전" << endl;
	int n = 0;
	for (int i = 0; i < 5; i++)
	{
		do
		{
			n = rand() % enemyCount;
		} while (!Targeting(enemys[n])&&CheckEnemysAlive((Creature**)enemys,enemyCount));
		int damage = this->_atk * 3;
		if (Targeting(enemys[n]))
		enemys[n]->Damaged(damage);

	}

}

void Archer::Sniping(Creature* enemys[], int enemyCount)
{

	cout << this->_name << "가 Sniping 시전" << endl;
	int n = 0;
	do
	{
		n = rand() % enemyCount;
	} while (!Targeting(enemys[n]) && CheckEnemysAlive((Creature**)enemys, enemyCount));

	int damage = this->_atk * 6;

	if (Targeting(enemys[n]))
	enemys[n]->Damaged(damage);
}
