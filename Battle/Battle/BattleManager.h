#pragma once
#include "pch.h"

class BattleManager
{
public:
	static BattleManager* GetInstance();
	static void Create();
	int TeamAllDead(vector<Creature*>& team);
	bool CheckBattleFinish(bool t1, bool t2);

public:
	void Update(vector<Creature*>& team1, vector<Creature*>& team2);

	void CreateTeam();
	
	void ClearTeam();

private:
	BattleManager();
	~BattleManager();

private:
	static BattleManager* _instance;

	vector<class Creature*> players;
	vector<class Creature*> monsters;


};
BattleManager* BattleManager::_instance = nullptr;
