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

	for (int i=targetIndex-1;i>=0 ;i--)
	{


		if ((enemys[i])->IsAlive())
		{
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
	for (int i = targetIndex + 1;i < enemys.size();i++)
	{


		if ((enemys[i])->IsAlive())
		{
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
	

	delete defaultTarget;
	
}
