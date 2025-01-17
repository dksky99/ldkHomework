#include "pch.h"
#include "Targeting.h"


#include "KingGoblin.h"

KingGoblin::KingGoblin(string name, int hp, int atk, int arm, int speed):Goblin(name, hp, atk, arm, speed)
{


}

void KingGoblin::Act(vector<Creature*>& enemys, vector<Creature*>& friendlys)
{
	if (!IsAlive())
	{
		return;
	}
		Revenge(enemys, friendlys);
	//int n = rand() % 5;
	//switch (n)
	//{
	//case 0:
	//case 1:
	//	Bite(enemys, friendlys);
	//	break;
	//case 2:
	//case 3:
	//	Smash(enemys, friendlys);
	//	break;
	//case 4:
	//default:
	//	Revenge(enemys, friendlys);
	//	break;
	//
	//}

}

void KingGoblin::Bite(vector<Creature*>& enemys, vector<Creature*>& friendlys)
{
	cout << this->_name << "�� Bite ����" << endl;
	int n = 0;
	Targeting* defaultTarget = new LowHPTargeting();


	int damage = this->_atk*5;

	Creature* target = (*defaultTarget)(*this, enemys, friendlys);
	if (target)
		target->Damaged(*this, damage);

	delete defaultTarget;

}

void KingGoblin::Smash(vector<Creature*>& enemys, vector<Creature*>& friendlys)
{
	cout << this->_name << "�� Smash ����" << endl;

	int n = 0;
	Targeting* defaultTarget = new RandomTargeting();



	int damage = this->_atk * 6;

	Creature* target = (*defaultTarget)(*this, enemys, friendlys);
	Creature* anotherTarget = nullptr;
	if (target)
		target->Damaged(*this, damage);
	int targetIndex = 0;
	for (int i = 0;i < enemys.size();i++)
	{
		if (enemys[i] == target)
		{
			targetIndex = i;
			break;
		}
	}
	//���� 1ĭ
	int anotherTargetIndex = targetIndex;
	for (int i = targetIndex - 1;i >= 0;i--)
	{


		if ((enemys[i])->IsAlive())
		{
			anotherTargetIndex = i;
			anotherTarget = enemys[i];
			break;
		}

	}
	if (anotherTarget != nullptr)
	{

		damage = this->_atk * 3;
		if (anotherTarget)
			anotherTarget->Damaged(*this, damage);
	}
	anotherTarget = nullptr;
	//���� 2ĭ
	if (anotherTargetIndex != targetIndex && anotherTargetIndex != 0)
	{
		for (int i = anotherTargetIndex - 1;i >= 0;i--)
		{


			if ((enemys[i])->IsAlive())
			{
				anotherTargetIndex = i;
				anotherTarget = enemys[i];
				break;
			}

		}
		if (anotherTarget != nullptr)
		{

			damage = this->_atk * 3;
			if (anotherTarget)
				anotherTarget->Damaged(*this, damage);
		}
	}

	//���� 1ĭ

	anotherTarget = nullptr;
	anotherTargetIndex = targetIndex;
	for (int i = targetIndex + 1;i < enemys.size();i++)
	{


		if ((enemys[i])->IsAlive())
		{
			anotherTargetIndex = i;
			anotherTarget = enemys[i];
			break;
		}

	}
	if (anotherTarget != nullptr)
	{

		damage = this->_atk * 3;
		if (anotherTarget)
			anotherTarget->Damaged(*this, damage);
	}

	anotherTarget = nullptr;

	//���� 2ĭ
	if (anotherTargetIndex != targetIndex && anotherTargetIndex <enemys.size()-1)
	{
		for (int i = anotherTargetIndex + 1;i < enemys.size();i++)
		{


			if ((enemys[i])->IsAlive())
			{
				anotherTargetIndex = i;
				anotherTarget = enemys[i];
				break;
			}

		}
		if (anotherTarget != nullptr)
		{

			damage = this->_atk * 3;
			if (anotherTarget)
				anotherTarget->Damaged(*this, damage);
		}
	}


	delete defaultTarget;

}

void KingGoblin::Revenge(vector<Creature*>& enemys, vector<Creature*>& friendlys)
{
	cout << this->_name << "�� Revenge ����" << endl;
	int n = 0;
	int damage = this->_atk * 2;
	RevengeTargeting* defaultTarget = new RevengeTargeting();
	for (int i = 0;i < 4;i++)
	{
		defaultTarget->rank = i;

		Creature* target = (*defaultTarget)(*this, enemys, friendlys);
		if (target)
			target->Damaged(*this, damage);

	}


	delete defaultTarget;

}

void KingGoblin::IamAggro(vector<Creature*>& enemys, vector<Creature*>& friendlys)
{
}
