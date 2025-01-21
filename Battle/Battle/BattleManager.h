#pragma once
#include "pch.h"

class BattleManager
{
public:
	static BattleManager* GetInstance();
	static void Create();
	int TeamAllDead(vector<shared_ptr<class Creature>>& team);
	bool CheckBattleFinish(bool t1, bool t2);

public:
	void Update(vector<shared_ptr<class Creature>>& team1, vector<shared_ptr<class Creature>>& team2);

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

	vector<shared_ptr<class Creature>> players;
	vector<shared_ptr<class Creature>> monsters;

	bool nowBattle=false;

};
