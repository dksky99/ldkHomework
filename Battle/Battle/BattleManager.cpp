#include "pch.h"
#include "Creature/Creature.h"

#include "Creature/Player.h"
#include "Creature/Knight.h"
#include "Creature/Archer.h"
#include "Creature/Mage.h"

#include "Creature/Monster.h"
#include "Creature/Goblin.h"

#include "BattleManager.h"


int BattleManager::TeamAllDead(vector<Creature*>& team)
{
    int n = 0;
    for (auto iter = team.begin(); iter != team.end(); iter++)
    {
        if ((*iter)->IsAlive())
        {
            n++;
        }
    }
    cout << team.size() << "중 " << n << "인 생존" << endl;
    return n;

}
bool BattleManager::CheckBattleFinish(bool t1, bool t2)
{
    cout << t1 << t2 << endl;
    return t1 || t2;

}

BattleManager* BattleManager::GetInstance()
{
    if (!_instance)
        Create();

    return _instance;
}

void BattleManager::Create()
{
    if (_instance)
        return;
    _instance= new BattleManager();
}

void BattleManager::Update(vector<Creature*>& team1, vector<Creature*>& team2)
{
    bool turn = true;
    while (!CheckBattleFinish(TeamAllDead(players) == 0, TeamAllDead(monsters) == 0))
    {

        if (turn)
        {
            for (auto iter = players.begin(); iter != players.end(); iter++)
            {
                (*iter)->Act(monsters, players);
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

}

void BattleManager::CreateTeam()
{
    
    players.push_back(new Archer("M1", 100, 10, 8, 10));

    std::cout << "플레이어 " << players.size() << "인 생성 완료" << endl;
    
    monsters.push_back(new Goblin("G0", 50, 5, 3, 10));
    monsters.push_back(new Goblin("G1", 50, 5, 3, 10));
    monsters.push_back(new Goblin("G2", 50, 5, 3, 10));
    monsters.push_back(new Goblin("G3", 50, 5, 3, 10));
    monsters.push_back(new Goblin("G4", 50, 5, 3, 10));
    monsters.push_back(new Goblin("G5", 50, 5, 3, 10));
    monsters.push_back(new Goblin("G6", 50, 5, 3, 10));
    monsters.push_back(new Goblin("G7", 50, 5, 3, 10));
    monsters.push_back(new Goblin("G8", 50, 5, 3, 10));
    monsters.push_back(new Goblin("G9", 50, 5, 3, 10));

    std::cout << "몬스터 " << monsters.size() << "인 생성 완료" << endl;

}

void BattleManager::ClearTeam()
{

    cout << "할당 해제" << endl;
    for (auto iter = players.begin(); iter != players.end(); iter++)
    {
        delete* iter;

    }
    players.clear();

    for (auto iter = monsters.begin(); iter != monsters.end(); iter++)
    {
        delete* iter;

    }
    monsters.clear();
}


BattleManager::BattleManager()
{
    _instance = this;
}

BattleManager::~BattleManager()
{
    delete _instance;
}
