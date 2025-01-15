#pragma once
#include "Player.h"
class Mage :
    public Player
{
public:
	Mage(string name, int hp, int atk, int arm, int speed);
	void Act(Creature* enemys[], int enemyCount,  Creature* friendlys[], int friendCount) override;
	void LightningPierce( Creature* enemys[], int enemyCount);
	void FireStorm(Creature* enemys[], int enemyCount);
	
private:



};

