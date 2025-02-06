#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

#pragma region �׷���
/*
	�׷��� : Vertex�� edge�� �̷���� �ڷᱸ��
	
	adjacent : �������ִ�.

	����Ǿ��ִ� ����� ��ȣ�� ����Ʈ��

	��ġ��� : ����� �밢���� �������� �����°�.
	����� �׷��� A�� A�� ��ġ��� (A)�� ���� ����.

	�ܹ��� �׷����� �ٸ���

	���� ��� : �ڽŰ� ����� ��带 

	������� : �ڽŰ� �ٸ�������� ������踦 ���� ����� ����Ʈ
	��ǻ�� ���п��� ���� �� ������� ǥ���Ѵ�.

	�׷����� ��ȸ��� : 
	DFS(Deep FIrst Search) : ���� �켱 Ž��


	BFS(Breadth First Search) : �ʺ� �켱 Ž��




*/

#pragma endregion



vector<vector<int>> adjacent_list; //���� ���
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

vector<vector<bool>> adjacent; //���� ���
// -�����͸� ���� �Դ���, Ž���ϴµ� ����� �ð��� �ɸ���.

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
	//0�� 2�� ���� ������ �Ǿ��ֳ�
	auto iter=find(adjacent_list[0].begin(), adjacent_list[0].end(), 2);

	if (iter != adjacent_list[0].end())
	{
		cout << *iter << endl;
	}

	//Ʈ���Ϳ��� a�� b�� ģ���ΰ�?
	//�� ����� ���� �����ߴ��� �˻��ҋ� n���̰ɸ�

	if (adjacent[0][2])
	{
		//�� ������ Ȯ���� �� ����� ���� �ɸ���.
		//������ ��� ������ Ȯ�ν������ �ϱ⿡ �뷮�� ���� �Դ´�.



	}


	return 0;

}