#include "pch.h"
#include "Targeting.h"
#include "Knight.h"

Knight::Knight(string name, int hp, int atk, int arm, int speed) :Player(name, hp, atk, arm, speed)
{
	cout << "기사 생성" << endl;
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
	cout << this->_name << "가 Smite 시전" << endl;

	int n = 0;
	Targeting* defaultTarget = new RandomTargeting();


	
	int damage = this->_atk * 4;

	Creature* target = (*defaultTarget)(*this, enemys, friendlys);
	if (target)
		target->Damaged(*this, damage);

	delete defaultTarget;


	
}

//질문사항 : iter을 사용한 반복문은 보통 begin에서 end로 순차적으로 실행 begin은 0번 인덱스를 가리키지만 end는 마지막인덱스너머를 가리키고있음
// 그러면 역순으로 탐색하려면 어떻게해야할까요


void Knight::MoonSlash(vector<Creature*>& enemys, vector<Creature*>& friendlys)
{
	cout << this->_name<<"가 MoonSlash 시전" << endl;

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
