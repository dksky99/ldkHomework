#include "pch.h"
#include "Creature/Creature.h"
#include "Targeting.h"
#include "StateAbnormality.h"
#include "State.h"


State::~State()
{
	for (auto iter = Dots.begin();iter != Dots.end();iter++)
	{
		delete(*iter);
		*iter = nullptr;
	}
	for (auto iter = Inabilitys.begin();iter != Inabilitys.end();iter++)
	{
		delete(*iter);
		*iter = nullptr;
	}
	for (auto iter = Aggros.begin();iter != Aggros.end();iter++)
	{
		delete(*iter);
		*iter = nullptr;
	}
	for (auto iter = Disarrays.begin();iter != Disarrays.end();iter++)
	{
		delete(*iter);
		*iter = nullptr;
	}
	Dots.clear();
	Inabilitys.clear();
	Aggros.clear();
	Disarrays.clear();

	

}

void State::AddStateAbnormality(StateAbnormality* abnormality)
{
	switch (abnormality->GetType())
	{
	case Dot:
	{
		Dots.push_back(abnormality);
		myState = myState | EStateAbnormality::Dot;

		break;
	}
	case Inability:
	{
		Inabilitys.push_back(abnormality);
		myState = myState | EStateAbnormality::Inability;

	}
		break;
	case Aggro:
	{
		Aggros.push_back(abnormality);
		myState=myState | EStateAbnormality::Aggro;

	}
		break;
	case Disarray:
	{

		Disarrays.push_back(abnormality);

		myState = myState| EStateAbnormality::Disarray;
	}
		break;
	default:
		break;
	}
}

void State::UpdateDots(Creature& owner)
{
	for_each(Dots.begin(), Dots.end(), [](StateAbnormality* i)
		{
			i->TurnDown();

		}
	);
	remove_if(Dots.begin(), Dots.end(), [](StateAbnormality* i) {return i->IsFinished(); });

	if (Dots.size() == 0)
		myState = myState^ EStateAbnormality::Dot;
}

void State::UpdateInability(Creature& owner)
{
	for_each(Inabilitys.begin(), Inabilitys.end(), [](StateAbnormality* i)
		{
			i->TurnDown();

		}
	);
	remove_if(Inabilitys.begin(), Inabilitys.end(), [](StateAbnormality* i) {return i->IsFinished(); });

	if (Inabilitys.size() == 0)
		myState = myState^ EStateAbnormality::Inability;
}

void State::UpdateAggro(Creature& owner)
{

	for_each(Aggros.begin(), Aggros.end(), [](StateAbnormality* i)
		{
			i->TurnDown();
			
		}
	);
	remove_if(Aggros.begin(), Aggros.end(), [](StateAbnormality* i) {return i->IsFinished(); });

	if (Aggros.size() == 0)
		myState=myState^ EStateAbnormality::Aggro;


}

void State::UpdateDisarray(Creature& owner)
{
	for_each(Disarrays.begin(), Disarrays.end(), [](StateAbnormality* i)
		{
			i->TurnDown();

		}
	);
	remove_if(Disarrays.begin(), Disarrays.end(), [](StateAbnormality* i) {return i->IsFinished(); });

	if (Disarrays.size() == 0)
		myState = myState^ EStateAbnormality::Disarray;

}

bool State::IsActable()
{
	


	return !(myState&EStateAbnormality::Inability);
}

Targeting* State::GetTarget()
{
	//어그로의 경우 마지막에 걸린 어그로가 유효. 
	if (myState & EStateAbnormality::Aggro)
	{
		auto temp = Aggros.end();
		temp--;
		
		StateAbnormality_Aggro* aggro = dynamic_cast<StateAbnormality_Aggro*>(*temp);
		
		return (aggro->GetTargeting());
	}
	else if (myState & EStateAbnormality::Disarray)
	{
		return new RandomTargeting;
	}
	else
	{
		return nullptr;

	}

}
