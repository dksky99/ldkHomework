#pragma region 솔루션과 프로젝트
/*
	sln : 솔루션(solution)
	- 편집기에서 서점과 비슷
	- 좀 포괄적인 역할.

	proj : 프로젝트(project)
	- 편집기에서 서점의 구역과 비슷
	
	ctrl c+ ctrl k : 주석처리

	함수의 선언부, 정의부

	void Hello(); //함수의 선언

	void Hello() //함수의 정의
	{

	}
	링커가 헤더와 c++파일로 분리된 파일을 합쳐줌. 여기서 문제가 나면 링커 오류가 난다.

	미리 컴파일된 헤더파일. : 미리 한번 해석해봣다.

	#pragma once : 한번 읽어봤으면 그냥 넘어가라.


*/
#pragma endregion
#include"pch.h"

#include "Creature/Creature.h"

#include "Creature/Player.h"
#include "Creature/Knight.h"
#include "Creature/Archer.h"
#include "Creature/Mage.h"

#include "Creature/Monster.h"
#include "Creature/Goblin.h"




int TeamAllDead(vector<Creature*>& team)
{
	int n = 0;
	for (auto iter= team.begin(); iter !=team.end(); iter++)
	{
		if ((*iter)->IsAlive())
		{
			n++;
		}
	}
	cout <<team.size()<<"중 " << n << "인 생존" << endl;
	return n;

}
bool CheckBattleFinish(bool t1,bool t2)
{
	cout << t1 << t2 << endl;
	return t1 || t2;
	
}
int main()
{
	srand(time(NULL));
	int select=0;
	cout << "1.기사 2.궁수 3.마법사 : ";
	cin >> select;

	vector<Creature*> players;
	players.push_back( new Archer("M1",100,10,8,10) );

	std::cout << "플레이어 " << players.size() << "인 생성 완료" << endl;
	vector<Creature*> monsters=
	{
		new Goblin("G0",50,5,3,10),
		new Goblin("G1",50,5,3,10),
		new Goblin("G2",50,5,3,10),
		new Goblin("G3",50,5,3,10),
		new Goblin("G4",50,5,3,10),
		new Goblin("G5",50,5,3,10),
		new Goblin("G6",50,5,3,10),
		new Goblin("G7",50,5,3,10),
		new Goblin("G8",50,5,3,10),
		new Goblin("G9",50,5,3,10)
	};
	int aliveMonster[10] = { 0,1,2,3,4,5,6,7,8,9 };
	std::cout << "몬스터 " << monsters.size() << "인 생성 완료" << endl;
	
	bool turn=true;
	while (!CheckBattleFinish( TeamAllDead(players) == 0, TeamAllDead(monsters) == 0))
	{
		
		if (turn)
		{
			for (auto iter = players.begin(); iter!=players.end(); iter++)
			{
				(*iter)->Act(monsters,players);
			}

		}
		else
		{
			for (auto iter = monsters.begin(); iter != monsters.end(); iter++)
			{
				(*iter)->Act(players, monsters);
			}
		}
		
		turn = !turn;

	}
	cout << "전투 종료" << endl;
	if (turn)
	{
		std::cout << "플레이어 전멸. 몬스터 승리" << endl;
		for (auto iter = monsters.begin(); iter != monsters.end(); iter++)
		{
			(*iter)->PrintCreature();
		}
	}
	else
	{
		std::cout << "몬스터 전멸. 플레이어 승리" << endl;
		for (auto iter = players.begin(); iter != players.end(); iter++)
		{
			(*iter)->PrintCreature();
		}
	}
	cout << "할당 해제" << endl;
	for (auto iter = players.begin(); iter != players.end(); iter++)
	{
		delete *iter;
		iter=players.erase(iter);

	}
	for (auto iter = monsters.begin(); iter != monsters.end(); iter++)
	{
		delete* iter;
		iter = monsters.erase(iter);

	}


	return 0;
}
