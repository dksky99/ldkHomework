#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

#pragma region 너비우선 탐색
/*

	깊이 :  그래프에서 몇번을 걸쳐 갈 수 있는지에대한 정도?
	깊이가 1이면 1번의 이동으로 갈 수 있는것

	너비 우선 탐색 : 깊이가 낮은 순으로 탐색.
	
	최단 거리를 찾아야 할때 사용이 많이됨.
	경로 찾기 문제에 좋다.

	도착지에서 부모를 타고 올라가다 자신을 부모로 둔사람이 나올때까지 세면 그게
	깊이.
	
	순회 방법 : 
	큐를 이용.
	처음 시작하는 정점에서 이동가능한 정점을 추가하고 이후 다른 노드를 방문할 때 마다
	그 노드의 이동가능한 정점을 큐에 추가하고 이미 탐색한 노드를 큐에서 지운다.

	큐에 더이상 노드가 남아있지 않다면 순환을 종료

	


*/

#pragma endregion



vector<vector<bool>> adjacent; //인접 행렬
vector<bool> discovered; //탐색 완료한 노드인지 기록
vector<int> parent;//탐색을 진행하며 어느 노드로부터 왔는지 확인하는지 기록

void CreateGraph()
{
	adjacent = vector < vector < bool>>(7, vector<bool>(7, false)); //7x7
	//adjacent.resize(7,vector<bool>(7,false))
	discovered = vector<bool>(7, false);
	parent = vector<int>(7, -1);

	adjacent[0][0] = true;
	adjacent[0][1] = true;
	adjacent[0][2] = true;
	adjacent[0][3] = true;


	adjacent[1][0] = true;
	adjacent[1][1] = true;
	adjacent[1][4] = true;

	adjacent[2][0] = true;
	adjacent[2][2] = true;
	adjacent[2][5] = true;
	adjacent[2][6] = true;

	adjacent[3][0] = true;
	adjacent[3][3] = true;

	adjacent[4][1] = true;
	adjacent[4][4] = true;

	adjacent[5][2] = true;
	adjacent[5][5] = true;

	adjacent[6][2] = true;
	adjacent[6][6] = true;



}

void BFS(int start)
{
	discovered[start] = true;
	parent[start] = start;
	queue<int> q;

	q.push(start);
	while (true)
	{
		if (q.empty())
			break;

		int here = q.front();
		cout << here << endl;
		q.pop();
		
		for (int there = 0;there < adjacent.size();there++)
		{
			//here와 there가 같냐
			if (here == there)
				continue;
			//here와 there가 인접해있는가
			if (adjacent[here][there] == false)
				continue;
			//이미 방문했는가
			if (discovered[there] == true)
				continue;

			q.push(there);

			discovered[there]=true;

			parent[there] = here;


			
			
		}



	}


}

int main()
{
	CreateGraph();

	BFS(0);

	//특정 노드의 깊이를 확인.
	int distance = 0;
	int tempParent = 6;
	while (true)
	{
		if (tempParent == parent[tempParent])
			break;
		tempParent = parent[tempParent];
		distance++;
	}
	cout << distance<<endl;


	return 0;
}