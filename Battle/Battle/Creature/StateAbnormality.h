#pragma once
#include "Targeting.h"

enum EStateAbnormality
{
	Dot = 1,
	Inability = 1 << 1,
	Aggro = 1 << 2,
	Disarray = 1 << 3

};


class StateAbnormality
{
public:
	virtual ~StateAbnormality()=0;
	void TurnDown() { _duration--; }
	bool GetPurifiable() { return _purifiable; }
	void Purify() {}

protected:

	bool _purifiable=true;
	int _duration=0;
	EStateAbnormality _state;
};





class StateAbnormality_Aggro : public StateAbnormality
{
public:
	virtual ~StateAbnormality_Aggro()override;
	void SetTarget(class Creature* target, int duration)
	{
		_duration = duration;
		_targeting = new AggroTargeting();
		_targeting->target = target;
	}
	Targeting* GetTargeting(){return _targeting;}


private:

	AggroTargeting* _targeting;


};
