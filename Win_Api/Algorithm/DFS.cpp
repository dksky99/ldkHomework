#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

#pragma region 깊이우선 탐색
/*
	깊이 우선 탐색 : 하나의 연결에서 
	
	스택프레임을 활용
	==> 재귀 함수 사용

	깊이 우선에선 부모란 개념이 굳이 필요하지 않음.


	닫힌 계 : 특정 지점에 도달할 수 없는지
	
	열린 계 : 

	BFS vs DFS
	
	BFS : 길찾기(최단거리 찾기)



	DFS : 길찾기를 제외한 모든 방법.=>닫힌계 찾기.
	닫힌계 찾기엔 DFS에서 찾기 좋다. 
	DFS에서는 최단거리를 찾을 수 없다. 만약 순환구조라면 더 가까이 갈 수 있는 곳을 더 멀리 
	갈 수 있고 그걸 최단거리로 등록할수밖에 없어서 

	구조를 파악하는데 용의함




*/

#pragma endregion



vector<vector<bool>> adjacent; //인접 행렬
vector<bool> visited; //탐색 완료한 노드인지 기록

void CreateGraph()
{
	adjacent = vector < vector < bool>>(7, vector<bool>(7, false)); //7x7
	//adjacent.resize(7,vector<bool>(7,false))
	visited = vector<bool>(7, false);

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

void DFS(int here)
{
	visited[here] = true;
	cout << here << endl;
	for (int there = 0;there < adjacent.size();there++)
	{
		if (here == there)
			continue;
		if (visited[there] == true)
			continue;
		if (adjacent[here][there] == false)
			continue;

		DFS(there);


	}


}

int main()
{
	CreateGraph();

	DFS(0);



	return 0;
}