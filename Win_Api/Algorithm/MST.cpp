#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

#pragma region MST
/*
	스패닝 트리.
	- 그래프 내의 모든 정점을 포함하지만 사이클이 없는(다시 방문 못함) 트리
	- 노드가 n개 있으면 간선은 n-1개이다.
	- 스패닝트리는 한 그래프에서 여럿 존재할 수 있다.

	최소 스패닝 트리
	스패닝 트리 중 사용된 간선들의 가중치 합이 최소인 트리

	작성 방법 :  
	1 : 간선의 코스트가 적은 순으로 연결
	2 : 같은 코스트라면 인덱스가 작은순으로 연결

	이러다보면 최선의 결과가 나올것이다.
	크루스칼 알고리즘.
	탐욕법중 대표적인 알고리즘


*/
#pragma endregion








struct User
{

	int guildId = 0;


};

class DisJointSet;


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


vector<vector<int>> adjacent; //인접 행렬
vector<class Edge> edges;

void CreateGraph()
{
	adjacent = vector < vector < int>>(7, vector<int>(7, -1)); //7x
	adjacent[0][0] = 0;
	adjacent[0][1] = 1;
	adjacent[0][2] = 10;
	adjacent[0][3] = 5;


	adjacent[1][0] = 1;
	adjacent[1][1] = 0;
	adjacent[1][2] = 5;
	adjacent[1][4] = 5;

	adjacent[2][0] = 10;
	adjacent[2][1] = 5;
	adjacent[2][2] = 0;
	adjacent[2][5] = 3;
	adjacent[2][6] = 8;

	adjacent[3][0] = 5;
	adjacent[3][3] = 0;
	adjacent[3][6] = 10;

	adjacent[4][1] = 5;
	adjacent[4][4] = 0;

	adjacent[5][2] = 3;
	adjacent[5][5] = 0;

	adjacent[6][2] = 9;
	adjacent[6][3] = 10;
	adjacent[6][6] = 0;



}


struct Edge
{
	int u;
	int v;
	
	int cost;

};

void CreateEdges()
{
	for (int u = 0;u < adjacent.size();u++)
	{
		for (int v = 0;v < adjacent.size();v++)
		{
			if (adjacent[u][v] < 0)
				continue;
			//양방향 그래프면 2번씩 나오게될 수 있으니 한번씩만 나오도록.
			if (u >= v)
				continue;


			Edge edge;
			edge.u = u;
			edge.v = v;
			edge.cost = adjacent[u][v];

			edges.push_back(edge);

		}
	}

}

vector<Edge> Kruskal()
{
	vector<Edge> result;

	//코스트가 낮은순으로 정렬.
	sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b)->bool {return a.cost < b.cost;});


	//사이클 방지를 위해. 서로소 집합을 사용. 이미 같은 집합에 있다면 배제한다.
	DisJointSet set(adjacent.size());

	for (auto edge : edges)
	{
		int u = edge.u;
		int v = edge.v;

		//같은 집합인가.
		if (set.FindLeader(u) == set.FindLeader(v))
			continue;

		result.push_back(edge);
		set.Merge(u, v);

	}




	return result;
	
}


int main()
{
	CreateGraph();
	CreateEdges();

	auto mst = Kruskal();

	for (auto edge : mst)
	{
		cout << "u : " << edge.u << ", v : " << edge.v << ", Cost : " << edge.cost << endl;
	}

	return 0;
}