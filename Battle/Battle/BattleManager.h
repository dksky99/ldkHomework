#pragma once
#include "pch.h"

class BattleManager
{
public:
	static BattleManager* GetInstance();
	static void Create();
	int TeamAllDead(vector<class Creature*>& team);
	bool CheckBattleFinish(bool t1, bool t2);

public:
	void Update(vector<class Creature*>& team1, vector<class Creature*>& team2);

	void CreateTeam();
	
	void ClearTeam();
	bool StartBattle();
	void Battle();
	void EndBattle();
private:
	BattleManager();
	~BattleManager();

private:
	static BattleManager* _instance;

	vector<class Creature*> players;
	vector<class Creature*> monsters;

	bool nowBattle=false;

};
