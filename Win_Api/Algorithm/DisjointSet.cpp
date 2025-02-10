#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

#pragma region ������ �ʴ� ����
/*
	NaiveDisjointSet : ���μ� ����



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

	//555�� ������ 1��° ���� ��忡 ����
	users[555].guildId = users[1].guildId;

	//guild Id �� 2�� �������� 1��忡 ���� =>n��ŭ�� �ð����⵵

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


	//�־��� ��� n���� �ɸ���. 
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

		//���� ��� �Ҽ��̳�
		if (uLeader == vLeader)
			return;
		//��ǥ����� ������ ����.
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
	//�־��� ��� n���� �ɸ���. 
	int FindLeader(int u)
	{
		if (u == _parent[u])
			return u;
		int parent = _parent[u];
		return FindLeader(parent);
	}

	//��ũ�� ���ؼ� ��ũ�� �������� ������ ������ ���°� ����

	void Merge(int u, int v)
	{
		int uLeader = FindLeader(u);
		int vLeader = FindLeader(v);

		//���� ��� �Ҽ��̳�
		if (uLeader == vLeader)
			return;

		if (_rank[uLeader] > _rank[vLeader])
		{
			swap(uLeader, vLeader);
		}

		//vLeader�� ��ũ�� �׻� ũ�ų� ����.

		


		//��ǥ����� ������ ����.
		_parent[uLeader] = vLeader;

		//���� ��ũ�� ������ vLeader�� ũ�� 1����.
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