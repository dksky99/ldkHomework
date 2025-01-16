#pragma once
#include "Player.h"
class Mage :
    public Player
{
public:
	Mage(string name, int hp, int atk, int arm, int speed);



	void Act(vector<Creature*>& enemys, vector<Creature*>& friendlys) override;

	void LightningPierce(vector<Creature*>& enemys, vector<Creature*>& friendlys);
	void FireStorm(vector<Creature*>& enemys, vector<Creature*>& friendlys);

	
private:



};

