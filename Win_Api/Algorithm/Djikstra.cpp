#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

#pragma region ���ͽ�Ʈ��
/*
	
	����ġ �׷���:
	�������� �ڽ�Ʈ���ϴ� ����ġ�� ����
	���� ����� �ܼ��� �����ٴ� �游�̾ƴ϶� �׾ȿ� �ɸ��� �ڽ�Ʈ�� �����ְ� �ؾ���.
	�����ߴٸ� ����� �ƴ϶�� -1�̳� �ڷ����� �ִ밪�̳� �ּҰ��� �پ��ϰ�

	���� BFS�� �޸� �̹� �ٳ�� ��带 �ٽ� �ٸ� ������� �湮�Ͽ� �ְ�� �ڽ�Ʈ�� ����
	����� ã�ƾ� �ؼ� bool ����Ʈ�� discovered�� �ƴ϶� int ����Ʈ�� best�� ����Ѵ�
	best�� int_max�� �ʱ�ȭ.

	�ּ� ����ġ�� ���� ������ Ž���ؾ� �ؼ� �ּ� ���� ����ؾ���.

	���ͽ�Ʈ�� �˰����� ���������� �ٸ� ��������� ����ġ�� Ȯ���ϰ� �ְ� ȿ���� ��Ʈ�� ã�� 
	�˰���. 
	�ݵ�� �������� �ʿ�.
	




*/

#pragma endregion

vector<vector<int>> adjacent; //���� ���
vector<int> best; //�ڽ�Ʈ ����Ʈ
vector<int> parent;//Ž���� �����ϸ� ��� ���κ��� �Դ��� Ȯ���ϴ��� ���

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
	int _cost = 0;	//������������ ����ġ
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
		//pq�� ����ɸ� Vertex�� ���´µ� �� ���� ��ΰ� �̹� �߰ߵ�����.
		if (best[here] < hereV._cost)
		{
			cout << "�� ���� ��ΰ� ������ �߰ߵ�" << endl;
			cout << here << endl;
			cout << hereV._cost << endl;
			cout << best[here] << endl;
			continue;
		}
		for (int there = 0;there < adjacent.size();there++)
		{
			//�ڽ��̸� ������
			if (here == there)
				continue;
			//���� �ȵ������� ������
			if (adjacent[here][there] == -1)
				continue;

			//������� �������ִ�.

			//���������� ���� ������ �ɸ��� �ڽ�Ʈ.
			int thereCost = hereV._cost + adjacent[here][there];

			//������ �߰��� ���� best�� �� �۾Ҵ�. -> �̰� ������ ����. �������� ����.
			if (thereCost >= best[there])
				continue;
			
			//ť�� �߰����ְ� �ְ�ȿ�� �ڽ�Ʈ�� �θ� ����.
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