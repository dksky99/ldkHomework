#pragma once
class BattleManager
{
public:
	static BattleManager* GetInstance();
	static void Create();

public:
	void Update(vector<Creature*>& team1, vector<Creature*>& team2);


private:
	BattleManager();
	~BattleManager();

private:
	static BattleManager* _instance;


};
BattleManager* BattleManager::_instance = nullptr;
