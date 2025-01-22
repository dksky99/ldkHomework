#pragma once
#include "Monster.h"
class Goblin :
    public Monster
{
public:
	Goblin(string name, int hp, int atk, int arm, int speed);
	void Act(vector<shared_ptr<Creature>>& enemys, vector<shared_ptr<Creature>>& friendlys) override;

	void Bite(vector<shared_ptr<Creature>>& enemys, vector<shared_ptr<Creature>>& friendlys);
};

