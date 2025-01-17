#include "pch.h"
#include "Creature/Creature.h"

#include "Creature/Player.h"
#include "Creature/Knight.h"
#include "Creature/Archer.h"
#include "Creature/Mage.h"

#include "Creature/Monster.h"
#include "Creature/Goblin.h"

#include "Creature/KingGoblin.h"

#include "BattleManager.h"


BattleManager* BattleManager::_instance = nullptr;


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
    if (_instance==nullptr)
        Create();

    return _instance;
}

void BattleManager::Create()
{
    if (_instance!=nullptr)
        return;
    _instance= new BattleManager();
}

void BattleManager::Update(vector<Creature*>& team1, vector<Creature*>& team2)
{
    static bool turn = true;
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

   

}

void BattleManager::CreateTeam()
{
    
    players.push_back(new Archer("A1", 120, 25, 12, 10));
    players.push_back(new Archer("A2", 160, 20, 12, 10));
    players.push_back(new Archer("A3", 140, 23, 12, 10));
    players.push_back(new Archer("A4", 130, 22, 12, 10));
    players.push_back(new Knight("K1", 300, 10, 20, 10));
    players.push_back(new Knight("K2", 200, 20, 15, 10));
    players.push_back(new Knight("K3", 250, 15, 16, 10));
    players.push_back(new Mage("M1", 100, 15, 8, 10));
    players.push_back(new Mage("M2", 120, 20, 8, 10));
    players.push_back(new Mage("M3", 140, 25, 8, 10));

    std::cout << "플레이어 " << players.size() << "인 생성 완료" << endl;
    
    //monsters.push_back(new Goblin("G0", 70, 6, 3, 10));
    //monsters.push_back(new Goblin("G1", 70, 6, 3, 10));
    //monsters.push_back(new Goblin("G2", 70, 6, 3, 10));
    //monsters.push_back(new Goblin("G3", 70, 6, 3, 10));
    monsters.push_back(new KingGoblin("KG4", 2000, 30, 25, 10));
    //monsters.push_back(new Goblin("G5", 70, 6, 3, 10));
    //monsters.push_back(new Goblin("G6", 70, 6, 3, 10));
    //monsters.push_back(new Goblin("G7", 70, 6, 3, 10));
    //monsters.push_back(new Goblin("G8", 70, 6, 3, 10));

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

bool BattleManager::StartBattle()
{
    if (nowBattle)
    {

        return false;
    }
    else
    {
        CreateTeam();
        Battle();
        return true;

    }

}

void BattleManager::Battle()
{
    while (TeamAllDead(players) != 0 && TeamAllDead(monsters) != 0)
    {
        Update(players, monsters);
    }
    EndBattle();
    
}

void BattleManager::EndBattle()
{

    if (TeamAllDead(players)==0)
    {
        std::cout << "플레이어 전멸. 몬스터 승리" << endl;
        for (auto iter = monsters.begin(); iter != monsters.end(); iter++)
        {
            if((*iter)->IsAlive())
                (*iter)->PrintCreature();
        }
    }
    else
    {
        std::cout << "몬스터 전멸. 플레이어 승리" << endl;
        for (auto iter = players.begin(); iter != players.end(); iter++)
        {
            if((*iter)->IsAlive())
                (*iter)->PrintCreature();
        }
    }

}


BattleManager::BattleManager()
{
    _instance = this;
}

BattleManager::~BattleManager()
{
    delete _instance;
}
