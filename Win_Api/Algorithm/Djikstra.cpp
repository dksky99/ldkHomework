#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

#pragma region 다익스트라
/*
	
	가중치 그래프:
	간선마다 코스트라하는 가중치가 존재
	인접 행렬이 단순히 연결됬다는 뜻만이아니라 그안에 걸리는 코스트를 갖고있게 해야함.
	인접했다면 양수로 아니라면 -1이나 자료형의 최대값이나 최소값등 다양하게

	기존 BFS와 달리 이미 다녀온 노드를 다시 다른 방법으로 방문하여 최고로 코스트가 낮은
	방법을 찾아야 해서 bool 리스트인 discovered가 아니라 int 리스트인 best를 사용한다
	best는 int_max로 초기화.

	최소 가중치를 가진 노드부터 탐색해야 해서 최소 힙을 사용해야함.

	다익스트라 알고리즘은 시작점부터 다른 노드들까지의 가중치를 확인하고 최고 효율의 루트를 찾는 
	알고리즘. 
	반드시 시작점이 필요.
	




*/

#pragma endregion

vector<vector<int>> adjacent; //인접 행렬
vector<int> best; //코스트 리스트
vector<int> parent;//탐색을 진행하며 어느 노드로부터 왔는지 확인하는지 기록

struct Vertex
{
	Vertex()
	{

	}
	Vertex(int vertexNum, int cost) : _vertexNum(vertexNum), _cost(cost)
	{

	}

	bool operator<(const Vertex& v) const
	{
		if (_cost < v._cost)
		{
			return true;
		}
		return false;
	}
	bool operator>(const Vertex& v) const
	{
		if (_cost > v._cost)
		{
			return true;
		}
		return false;
	}


	int _vertexNum = 0;
	int _cost = 0;	//시작점부터의 가중치
};


void CreateGraph()
{
	adjacent = vector < vector < int>>(7, vector<int>(7, -1)); //7x7
	parent = vector<int>(7, -1);
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


void Djikstra(int start)
{

	best = vector<int>(adjacent.size(), INT_MAX);
	priority_queue<Vertex,vector<Vertex>,greater<Vertex>> pq;

	Vertex startV = Vertex(start, 0);
	best[start] = 0;
	parent[start] = start;
	pq.push(startV);

	while (true)
	{
		if (pq.empty())
			break;

		Vertex hereV = pq.top();
		int here = hereV._vertexNum;

		pq.pop();
		//pq에 예약걸린 Vertex를 꺼냈는데 더 좋은 경로가 이미 발견됐을때.
		if (best[here] < hereV._cost)
		{
			cout << "더 좋은 경로가 이전에 발견됨" << endl;
			cout << here << endl;
			cout << hereV._cost << endl;
			cout << best[here] << endl;
			continue;
		}
		for (int there = 0;there < adjacent.size();there++)
		{
			//자신이면 다음거
			if (here == there)
				continue;
			//연결 안되있으면 다음거
			if (adjacent[here][there] == -1)
				continue;

			//여기부턴 인접해있다.

			//시작점에서 다음 노드까지 걸리는 코스트.
			int thereCost = hereV._cost + adjacent[here][there];

			//이전에 발견한 곳의 best가 더 작았다. -> 이건 쓸데가 없다. 다음것을 보자.
			if (thereCost >= best[there])
				continue;
			
			//큐에 추가해주고 최고효율 코스트와 부모를 갱신.
			Vertex thereV = Vertex(there, thereCost);
			pq.push(thereV);
			best[there] = thereCost;
			parent[there] = here;

		}
	}


}


int main()
{
	CreateGraph();
	Djikstra(0);

	int vertex = 6;
	cout << vertex << endl;
	while (true)
	{
		if (vertex == parent[vertex])
			break;
		vertex = parent[vertex];
		cout << vertex << endl;
	}

	return 0;
}