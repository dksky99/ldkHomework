#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

#pragma region �ʺ�켱 Ž��
/*

	���� :  �׷������� ����� ���� �� �� �ִ��������� ����?
	���̰� 1�̸� 1���� �̵����� �� �� �ִ°�

	�ʺ� �켱 Ž�� : ���̰� ���� ������ Ž��.
	
	�ִ� �Ÿ��� ã�ƾ� �Ҷ� ����� ���̵�.
	��� ã�� ������ ����.

	���������� �θ� Ÿ�� �ö󰡴� �ڽ��� �θ�� �л���� ���ö����� ���� �װ�
	����.
	
	��ȸ ��� : 
	ť�� �̿�.
	ó�� �����ϴ� �������� �̵������� ������ �߰��ϰ� ���� �ٸ� ��带 �湮�� �� ����
	�� ����� �̵������� ������ ť�� �߰��ϰ� �̹� Ž���� ��带 ť���� �����.

	ť�� ���̻� ��尡 �������� �ʴٸ� ��ȯ�� ����

	


*/

#pragma endregion



vector<vector<bool>> adjacent; //���� ���
vector<bool> discovered; //Ž�� �Ϸ��� ������� ���
vector<int> parent;//Ž���� �����ϸ� ��� ���κ��� �Դ��� Ȯ���ϴ��� ���

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
			//here�� there�� ����
			if (here == there)
				continue;
			//here�� there�� �������ִ°�
			if (adjacent[here][there] == false)
				continue;
			//�̹� �湮�ߴ°�
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

	//Ư�� ����� ���̸� Ȯ��.
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