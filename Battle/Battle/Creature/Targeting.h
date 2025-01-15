#include "pch.h"
#include "Creature/Creature.h"

class Targeting
{
public:
	virtual Creature* operator()(Creature& owner, vector<Creature*> enemys, vector<Creature*> friendlys) =0;
};

class RandomTargeting :public Targeting
{
public:
	virtual Creature* operator()(Creature& owner, vector<Creature*> enemys, vector<Creature*> friendlys) override;


};

class RevengeTargeting :public Targeting
{
public:
	virtual Creature* operator()(Creature& owner, vector<Creature*> enemys, vector<Creature*> friendlys)override;
public:
	int rank=0;

};

class LowHPTargeting :public Targeting
{
public:
	virtual Creature* operator()(Creature& owner, vector<Creature*> enemys, vector<Creature*> friendlys)override;

};
class HighHPTargeting :public Targeting
{
public:
	virtual Creature* operator()(Creature& owner, vector<Creature*> enemys, vector<Creature*> friendlys)override;

};

class AggroTargeting :public Targeting
{
public:
	virtual Creature* operator()(Creature& owner, vector<Creature*> enemys, vector<Creature*> friendlys)override;

public:
	Creature* target;

};



