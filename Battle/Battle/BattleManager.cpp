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
    _instance= new BattleManager();
}

void BattleManager::Update(vector<Creature*>& team1, vector<Creature*>& team2)
{
    //for (int i = 0;i < team1Size;i++)
    //{
    //    
    //}
}


BattleManager::BattleManager()
{
    _instance = this;
}

BattleManager::~BattleManager()
{
    delete _instance;
}
