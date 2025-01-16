#pragma once
#include <list>




class State
{
public:
	
	~State();

	void AddStateAbnormality(class StateAbnormality* abnormality);
	void UpdateDots(class Creature& owner);
	void UpdateInability(class Creature& owner);
	void UpdateAggro(class Creature& owner);
	void UpdateDisarray(class Creature& owner);
	bool IsActable();
	class Targeting* GetTarget();

private:
	
	list<class StateAbnormality*> Dots;
	list<class StateAbnormality*> Inabilitys;
	list<class StateAbnormality*> Aggros;
	list<class StateAbnormality*> Disarrays;

	unsigned int myState=0;

	

};

