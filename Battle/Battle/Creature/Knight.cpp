#include "pch.h"
#include "Targeting.h"
#include "Knight.h"

Knight::Knight(string name, int hp, int atk, int arm, int speed) :Player(name, hp, atk, arm, speed)
{
	cout << "��� ����" << endl;
}

void Knight::Act(vector<Creature*>& enemys, vector<Creature*>& friendlys)
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
		MoonSlash(enemys, friendlys);
		break;
	case 2:
	case 3:
	case 4:
	default:
		Smite(enemys, friendlys);
		break;

	}
}

void Knight::Smite(vector<Creature*>& enemys, vector<Creature*>& friendlys)
{
	cout << this->_name << "�� Smite ����" << endl;

	int n = 0;
	Targeting* defaultTarget = new RandomTargeting();


	
	int damage = this->_atk * 4;

	Creature* target = (*defaultTarget)(*this, enemys, friendlys);
	if (target)
		target->Damaged(*this, damage);

	delete defaultTarget;


	
}

//�������� : iter�� ����� �ݺ����� ���� begin���� end�� ���������� ���� begin�� 0�� �ε����� ����Ű���� end�� �������ε����ʸӸ� ����Ű������
// �׷��� �������� Ž���Ϸ��� ����ؾ��ұ��


void Knight::MoonSlash(vector<Creature*>& enemys, vector<Creature*>& friendlys)
{
	cout << this->_name<<"�� MoonSlash ����" << endl;

	int n = 0;
	Targeting* defaultTarget = new RandomTargeting();



	int damage = this->_atk * 6;

	Creature* target = (*defaultTarget)(*this, enemys, friendlys);
	if (target)
		target->Damaged(*this, damage);
	auto targetIter=find(enemys.begin(), enemys.end(), target);
	auto anotherTarget =enemys.end();
	for (auto iter=targetIter;iter != enemys.begin();iter--)
	{

		if (targetIter == iter)
			continue;

		if ((*iter)->IsAlive())
		{
			anotherTarget = iter;
			break;
		}

	}
	if (anotherTarget != enemys.end())
	{
		target = *anotherTarget;

		damage = this->_atk * 3;
		if (target)
			target->Damaged(*this, damage);
	}

	anotherTarget = enemys.end();
	for (auto iter = targetIter;iter != enemys.end();iter++)
	{
		if (targetIter == iter)
			continue;

		if ((*iter)->IsAlive())
		{
			anotherTarget = iter;
			break;
		}

	}
	if (anotherTarget != enemys.end())
	{
		target = *anotherTarget;

		damage = this->_atk * 3;
		if (target)
			target->Damaged(*this, damage);
	}
	

	delete defaultTarget;
	
}
