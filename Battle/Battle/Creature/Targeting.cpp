
#include "pch.h"
#include "Creature.h"
#include "Targeting.h"

shared_ptr<Creature> Targeting::operator()(shared_ptr<Creature> owner, vector< shared_ptr<Creature>>& enemys, vector< shared_ptr<Creature>>& friendlys)
{
	return nullptr;

}

shared_ptr<Creature> RandomTargeting::operator()(shared_ptr<Creature> owner, vector< shared_ptr<Creature>>& enemys, vector< shared_ptr<Creature>>& friendlys)
{

	vector<shared_ptr<Creature>> result;
	result.resize(enemys.size());
	auto iter = copy_if(enemys.begin(), enemys.end(), result.begin(), [](shared_ptr<Creature> i)
		{
			if (i == nullptr)
				return false;
			return i->IsAlive();
		});
	result.resize(std::distance(result.begin(), iter));  // shrink container to new size

	if (result.size() == 0)
		return nullptr;

	int n = rand() % result.size();
	auto iter2 = result.begin();
	for (int i = 0;i < n;i++)
	{

		iter2++;
	}


	return *iter2;
}
 shared_ptr<Creature> RevengeTargeting::operator()(shared_ptr<Creature> owner, vector< shared_ptr<Creature>>& enemys, vector< shared_ptr<Creature>>& friendlys)
{
	//기록된 입은피해 리스트의 수량보다 얻으려는 순위가 더 높다면 nullptr반환. 



	vector<pair<weak_ptr<Creature>, int>> rankList;
	vector<pair<weak_ptr<Creature>, int>> result;

	result.resize(enemys.size());

	for (auto iter = owner->GetHitRank().begin(); iter != owner->GetHitRank().end();iter++)
	{
		pair<weak_ptr<Creature>, int> temp = *iter;
		rankList.push_back(temp);
	}

	auto iter = rankList.begin();
	rankList.erase(iter = remove_if(rankList.begin(), rankList.end(), [](pair<Creature*, int> i) {return !(i.first->IsAlive());}), rankList.end());


	sort(rankList.begin(), rankList.end(), [](pair<Creature*, int> i, pair<Creature*, int> j) {return i.second > j.second;});

	if (rankList.size() <= rank)
		return nullptr;

	auto iter2 = find(enemys.begin(), enemys.end(), rankList[rank].first);

	if (iter2 != enemys.end())
	{
		cout << rankList[rank].second << "의 피해를 가한 적" << rankList[rank].first.lock()->GetName() <<endl;


		return *iter2;
	}

	return nullptr;
}




 shared_ptr<Creature> LowHPTargeting::operator()(shared_ptr<Creature> owner, vector< shared_ptr<Creature>>& enemys, vector< shared_ptr<Creature>>& friendlys)
 {

	 vector<shared_ptr<Creature>> result;
	 result.resize(enemys.size());
	 auto iter = copy_if(enemys.begin(), enemys.end(), result.begin(), [](Creature* i)
		 {
			 if (i == nullptr)
				 return false;
			 return i->IsAlive();
		 });
	 result.resize(std::distance(result.begin(), iter));  // shrink container to new size

	 if (result.size() == 0)
		 return nullptr;

	 sort(result.begin(), result.end(), [](Creature* i, Creature* j) {return i->GetHp() < j->GetHp();});




	 return *(result.begin());
 }



 shared_ptr<Creature> HighHPTargeting::operator()(shared_ptr<Creature> owner, vector< shared_ptr<Creature>>& enemys, vector< shared_ptr<Creature>>& friendlys)
 {

	 vector<shared_ptr<Creature>> result;
	 result.resize(enemys.size());
	 auto iter = copy_if(enemys.begin(), enemys.end(), result.begin(), [](Creature* i)
		 {
			 if (i == nullptr)
				 return false;
			 return i->IsAlive();
		 });
	 result.resize(std::distance(result.begin(), iter));  // shrink container to new size

	 if (result.size() == 0)
		 return nullptr;

	 sort(result.begin(), result.end(), [](Creature* i, Creature* j) {return i->GetHp() > j->GetHp();});




	 return *(result.begin());
 }

 shared_ptr<Creature> AggroTargeting::operator()(shared_ptr<Creature> owner, vector< shared_ptr<Creature>>& enemys, vector< shared_ptr<Creature>>& friendlys)
 {
	 if (target.expired())
	 {
		 return nullptr;
	 }

	 if (target.lock()->IsAlive())
	 {

		 return target.lock();
	 }

	 return nullptr;


 }

AggroTargeting::~AggroTargeting()
{
}
