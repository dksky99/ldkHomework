#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

#pragma region 그래프
/*
	그래프 : Vertex와 edge로 이루어진 자료구조
	
	adjacent : 인접해있다.

	연결되어있는 노드의 번호의 리스트와

	전치행렬 : 행렬을 대각선을 기준으로 뒤집는것.
	양방향 그래프 A는 A와 전치행렬 (A)와 서로 같다.

	단방향 그래프는 다르다

	인접 목록 : 자신과 연결된 노드를 

	인접행렬 : 자신과 다른노드들과의 연결관계를 전부 기록한 리스트
	컴퓨터 공학에선 보통 이 방법으로 표현한다.

	그래프의 순회방법 : 
	DFS(Deep FIrst Search) : 깊이 우선 탐색


	BFS(Breadth First Search) : 너비 우선 탐색




*/

#pragma endregion



vector<vector<int>> adjacent_list; //인접 목록
void CreateGraph_list()
{
	adjacent_list.resize(7);
	adjacent_list[0] = { 0,1,2,3 };
	adjacent_list[1] = { 0,1,4 };
	adjacent_list[2] = { 0,2,5,6 };
	adjacent_list[3] = { 0,3 };
	adjacent_list[4] = { 1,4 };
	adjacent_list[5] = { 2,5 };
	adjacent_list[6] = { 2,6 };
}

vector<vector<bool>> adjacent; //인접 행렬
// -데이터를 많이 먹더라도, 탐색하는데 상수의 시간이 걸린다.

void CreateGraph()
{
	adjacent = vector < vector < bool>>(7, vector<bool>(7 ,false)); //7x7
	//adjacent.resize(7,vector<bool>(7,false))

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



int main()
{

	CreateGraph_list();
	CreateGraph();
	//0과 2가 현재 연결이 되어있나
	auto iter=find(adjacent_list[0].begin(), adjacent_list[0].end(), 2);

	if (iter != adjacent_list[0].end())
	{
		cout << *iter << endl;
	}

	//트위터에서 a와 b가 친구인가?
	//위 방법을 사용시 인접했는지 검색할떄 n번이걸림

	if (adjacent[0][2])
	{
		//각 연결을 확인할 때 상수의 번이 걸린다.
		//하지만 모든 연결을 확인시켜줘야 하기에 용량을 많이 먹는다.



	}


	return 0;

}