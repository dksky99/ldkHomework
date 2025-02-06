#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

#pragma region 트리
/*

	트리
	1. 계층적 구조를 나타내는 자료구조(부모의 자식관계
	2. 트리는 잘라도 트리다 (서브트리 존재)
		-> 트리는 재귀적 속성을 갖는다.


	종류 :
	1. 이진트리 : 부모가 최대 2개의 자식을 갖는 트리
	2. 포화이진트리 :
	3. 완전 이진트리 :
	4. 힙 트리 :
	5. (자가균형) 이진탐색트리


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

	//트리의 전위 순회 :  부모- 왼쪽 자식들 - 오른쪽 자식들
	//트리의 중위 순회 :  왼쪽 자식- 부모 - 오른쪽 자식들
	//트리의 후위 순회 :  왼쪽 자식-  오른쪽 자식들- 부모

	//트리의 중위 순회
	//가운데 부터 보겠다.

	for (int i = 0;i < depth;i++)
	{
		cout << "-";
	}

	//전위 순회
	//cout << node->data << endl;
	for (auto child : node->children)
	{
		PrintTree(child, depth + 1);
	}
	//후위 순회
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