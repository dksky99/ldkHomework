#include "pch.h"
#include "Creature/Creature.h"

#include "BattleManager.h"

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
    new BattleManager();
}

void BattleManager::Update(Creature* team1[], int team1Size, Creature* team2[], int team2Size)
{
    for (int i = 0;i < team1Size;i++)
    {
        team1[i]
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
