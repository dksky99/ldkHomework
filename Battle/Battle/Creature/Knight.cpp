#include "pch.h"
#include "Knight.h"

Knight::Knight(string name, int hp, int atk, int arm, int speed) :Player(name, hp, atk, arm, speed)
{
	cout << "기사 생성" << endl;
}

void Knight::Act(Creature* enemys[], int enemyCount, Creature* friendlys[], int friendCount)
{
	if (!IsAlive())
	{
		return;
	}
	int n = rand() % 5;
	switch (n)
	{
	case 0:
	case 1:
		MoonSlash(enemys, enemyCount);
		break;
	case 2:
	case 3:
	case 4:
	default:
		Smite(enemys, enemyCount);
		break;

	}
}

void Knight::Smite(Creature* enemys[], int enemyCount)
{
	cout << this->_name << "가 Smite 시전" << endl;
	int n = 0;
	do
	{
		n = rand() % enemyCount;
	} while (!Targeting(enemys[n]) && CheckEnemysAlive((Creature**)enemys, enemyCount));
	
	int damage = this->_atk * 4;

	if (Targeting(enemys[n]))
		enemys[n]->Damaged(damage);
}

void Knight::MoonSlash(Creature* enemys[], int enemyCount)
{
	cout << this->_name<<"가 MoonSlash 시전" << endl;
	int n = 0;
	do
	{
		n = rand() % enemyCount;
	} while (!Targeting(enemys[n]) && CheckEnemysAlive((Creature**)enemys, enemyCount));
	

	int damage = this->_atk * 6;
	if (Targeting(enemys[n]))
		enemys[n]->Damaged(damage);
	int i = n;
	do
	{
		i -= 1;
		if (i < 0)
			break;
	} while (!Targeting(enemys[i]) && CheckEnemysAlive((Creature**)enemys, enemyCount));
	if (i >= 0)
	{
		damage = this->_atk * 3;
		if (Targeting(enemys[i]))
			enemys[i]->Damaged(damage);

	}
	i = n;
	do
	{
		i += 1;
		if (i >= enemyCount)
			break;
	} while (!Targeting(enemys[i]) && CheckEnemysAlive((Creature**)enemys, enemyCount));
	if (i <enemyCount)
	{
		damage = this->_atk * 3;
		if (Targeting(enemys[i]))
			enemys[i]->Damaged(damage);

	}
}
