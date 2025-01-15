#pragma once
class BattleManager
{
public:
	static BattleManager* GetInstance();
	static void Create();

public:
	void Update(class Creature* team1[],int team1Size, class Creature* team2[], int team2Size);


private:
	BattleManager();
	~BattleManager();

private:
	static BattleManager* _instance;


};

