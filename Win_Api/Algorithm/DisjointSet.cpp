#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

#pragma region 만나지 않는 집합
/*
	NaiveDisjointSet : 서로소 집합



*/
#pragma endregion

struct User
{

	int guildId = 0;


};

class NaiveDisJointSet;

void GuildSystem()
{
	vector<User> users;

	for (int i = 0;i < 1000;i++)
	{
		users.push_back({ i });
	}

	//555번 유저가 1번째 유저 길드에 병합
	users[555].guildId = users[1].guildId;

	//guild Id 가 2인 유저들이 1길드에 통합 =>n만큼의 시간복잡도

	for (auto& user : users)
	{
		if (user.guildId == 2)
		{
			user.guildId = 1;
		}
	}

	NaiveDisJointSet set(1000);
	set.Merge(555, 1);
	set.Merge(2, 1);


}

class NaiveDisJointSet
{
public:

	NaiveDisJointSet(int n)
	{
		_parent = vector<int>(n, 0);
		for (int i = 0;i <n; i++)
		{
			_parent[i] = i;
		}
	}


	//최악의 경우 n번이 걸린다. 
	int FindLeader(int u)
	{
		if (u == _parent[u])
			return u;
		int parent = _parent[u];
		return FindLeader(parent);
	}
	void Merge(int u, int v)
	{
		int uLeader = FindLeader(u);
		int vLeader = FindLeader(v);

		//같은 길드 소속이냐
		if (uLeader == vLeader)
			return;
		//목표길드장 밑으로 병합.
		_parent[uLeader] = vLeader;
	}

private:
	vector<int> _parent;

};

class DisJointSet
{
public: 
	DisJointSet(int n)
	{
		_parent = vector<int>(n, 0);
		for (int i = 0;i < n;i++)
		{
			_parent[i] = i;
		}
		_rank = vector<int>(n, 1);
	}
	//최악의 경우 n번이 걸린다. 
	int FindLeader(int u)
	{
		if (u == _parent[u])
			return u;
		int parent = _parent[u];
		return FindLeader(parent);
	}

	//랭크를 비교해서 랭크가 낮은쪽이 높은쪽 밑으로 들어가는게 좋음

	void Merge(int u, int v)
	{
		int uLeader = FindLeader(u);
		int vLeader = FindLeader(v);

		//같은 길드 소속이냐
		if (uLeader == vLeader)
			return;

		if (_rank[uLeader] > _rank[vLeader])
		{
			swap(uLeader, vLeader);
		}

		//vLeader의 랭크가 항상 크거나 같다.

		


		//목표길드장 밑으로 병합.
		_parent[uLeader] = vLeader;

		//같은 랭크를 가지면 vLeader의 크기 1증가.
		if (_rank[uLeader] == _rank[vLeader])
			_rank[vLeader]++;

	}

private:
	vector<int> _parent;
	vector<int> _rank;


};




int main()
{
	GuildSystem();


	return 0;
}