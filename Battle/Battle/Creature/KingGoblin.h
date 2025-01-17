#pragma once
#include "Goblin.h"
class KingGoblin :
	public Goblin
{
public:
	KingGoblin(string name, int hp, int atk, int arm, int speed);
	void Act(vector<Creature*>& enemys, vector<Creature*>& friendlys) override;

	void Bite(vector<Creature*>& enemys, vector<Creature*>& friendlys);
	void Smash(vector<Creature*>& enemys, vector<Creature*>& friendlys);
	void Revenge(vector<Creature*>& enemys, vector<Creature*>& friendlys);
	void IamAggro(vector<Creature*>& enemys, vector<Creature*>& friendlys);
};

