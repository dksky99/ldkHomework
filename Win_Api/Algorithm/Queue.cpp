#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include <deque>

using namespace std;

template<typename T,typename Container=list<T>>
class Queue
{
public:
	void push(T data) { datas.push_back(data); }
	void pop() { datas.pop_front(); }
	T front() { return datas.front(); }
	void clear() { datas.clear(); }
	bool empty() { return datas.empty(); }


private:

	Container datas;
};

int main()
{
	queue<int> q;
	q.push(10);
	q.push(2);
	q.push(15);
	q.push(1);
	q.push(3);

	while (true)
	{
		if (q.empty() == true)
		{
			break;
		}
		cout << q.front() << endl;
		q.pop();
	}


}