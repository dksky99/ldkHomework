#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

#pragma region Ʈ��
/*

	Ʈ��
	1. ������ ������ ��Ÿ���� �ڷᱸ��(�θ��� �ڽİ���
	2. Ʈ���� �߶� Ʈ���� (����Ʈ�� ����)
		-> Ʈ���� ����� �Ӽ��� ���´�.


	���� :
	1. ����Ʈ�� : �θ� �ִ� 2���� �ڽ��� ���� Ʈ��
	2. ��ȭ����Ʈ�� :
	3. ���� ����Ʈ�� :
	4. �� Ʈ�� :
	5. (�ڰ�����) ����Ž��Ʈ��


*/

#pragma endregion

struct Node
{
	string data;
	vector<Node*> children;
};

template<typename T,typename Pred,typename Container = vector<T>>
class PriorityQueue
{
public:
	void sorting_up(int index)
	{
		if (index <= 0)
			return;
		int parent = Parent(index);


		if (pred(v[parent] ,v[index]))
		{
			return;
		}

		Swap(parent, index);
		sorting_up(parent);
	}
	void sorting_down(int index)
	{
		if (HasChild(index)==false)
		{
			return;
		}

		int left = Left(index);
		int right = Right(index);

		int max = 0;
		if (right == v.size())
		{

			max = left;

		}
		else
		{
			if (pred(v[left] , v[right]))
			{
				max = left;
			}
			else
			{

				max = right;
			}
		}

		if (pred(v[index] , v[max]))
		{
			return;
		}
		Swap(index, max);
		sorting_down(max);
		
	}
	bool empty()
	{
		return v.empty();
	}
	T top()
	{
		return v[0];
	}

	void push(T n)
	{
		v.push_back(n);
		cout << "input" << n << endl;
		sorting_up(v.size() - 1);

	}
	void pop()
	{
		cout << "pop" << endl;
		v[0] = v.back();
		v.pop_back();
		sorting_down(0);

	}
private:
	void Swap(int i, int j)
	{
		int temp=v[i];
		v[i] = v[j];
		v[j] = temp;

	}
	int Left(int index)
	{
		return index * 2 + 1;
	}
	int Right(int index)
	{
		return index * 2 + 2;
	}
	int Parent(int index)
	{
		return (index - 1) / 2;
	}
	bool HasChild(int index)
	{
		return Left(index) < v.size();
	}

private:
	Container v;
	Pred pred;
};

template<typename T>
struct Less
{
	bool operator()(T a, T b)
	{
		return a < b;
	}
};
template<typename T>
struct Greater
{
	bool operator()(T a, T b)
	{
		return a > b;
	}
};

void PrintTree(Node* node, int depth = 0)
{

	//Ʈ���� ���� ��ȸ :  �θ�- ���� �ڽĵ� - ������ �ڽĵ�
	//Ʈ���� ���� ��ȸ :  ���� �ڽ�- �θ� - ������ �ڽĵ�
	//Ʈ���� ���� ��ȸ :  ���� �ڽ�-  ������ �ڽĵ�- �θ�

	//Ʈ���� ���� ��ȸ
	//��� ���� ���ڴ�.

	for (int i = 0;i < depth;i++)
	{
		cout << "-";
	}

	//���� ��ȸ
	//cout << node->data << endl;
	for (auto child : node->children)
	{
		PrintTree(child, depth + 1);
	}
	//���� ��ȸ
	cout << node->data << endl;
}


int main()
{
	PriorityQueue<int,Less<int>,vector<int>> pq;
	pq.push(100);
	pq.push(50);
	pq.push(75);
	pq.push(80);
	pq.push(70);

	while (true)
	{
		if (pq.empty())
			break;

		int top = pq.top();
		cout << top << endl;
		pq.pop();

	}






	return 0;
}