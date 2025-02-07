#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

#pragma region 우선순위 큐
/*

	제일 머리에서부터 나가기때문에 큐라고 함.
	최대 힙이면 0번이 제일크고 최소 힙이면 0번이 제일 작다.

	추가 할땐 마지막 번호에 추가하고 그 번호부터 부모와 비교하여 기준에 따라 스왑하여 자리를 잡음.
	log2(n)의 시간 복잡도를 가짐.
	제거 할땐 마지막 번호와 제일 앞번호을 스왑하고 부모로 간 말단이 자식과 비교하며 
	두 자식중 더 큰 자식이 자신과 스왑하여 자신의 자리를 찾아감.
	제거도 log2(n)의 시간 복잡도를 가짐.

	힙 정렬: 우선순위큐에 모든 데이터를 입력했다가 빼내면 정렬된상태로 나옴. 
	결과적으로  n*log(n)의 시간복잡도가 걸린다.

	부모는 자식의 인덱스에서 1을 빼고 2로 나누면 나오면 된다.
	자식의 인덱스는 부모의 인덱스의 2를 곱하고 왼쪽은 +1 오른쪽은 +2

	시간 복잡도 순
	n^3 > n^2 > nlog(n) > n > log(n) > 상수
	상수에 가까울수록 좋은 알고리즘.

	n^3 : 3중 for문
	n^2 : 버블정렬, 선택정렬, 순차정렬
	nlog(n) : 힙정렬
	n : 
	log(n) : 이진탐색
	상수 : 임의 접근 , 인덱스 접근, 해쉬테이블에서 접근, 리스트에서 원하는 위치에 삽입하는것


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