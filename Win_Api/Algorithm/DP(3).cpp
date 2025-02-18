#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
#include<stack>
#include<queue>
#include<algorithm>

using namespace std;

#pragma region �κ� ���� ����
/*
	Longest Increasing Sequence

	LIS : �κ� ���� ������

	{10,5,6,7,9} : �������� �ƴ�
	{1,10,11,15,30} ��������
	{6,7,9} �κ� ���� ����
	�κ� �������� : 
	{1} : �̰͵� �κ� ��������



	�������� ��� �������� �������� �̹� ���� ���� �̹����� ��ũ�� +





*/
#pragma endregion

vector<int> mem;
//vector<int> v = { 15,1,10,11, 30};
//vector<int> v = { 5,4,3,2, 1};
//vector<int> v = { 15,30,10,17,50};
vector<int> v = { 1,2,3,4,5};

int cache[1001];

int LIS(int n)
{
	if (n >= v.size())
		return 0;

	int& ref = cache[n];
	if (ref != -1)
	{
		return ref;
	}



	int temp = 0;
	for (int i = n+1;i < v.size();i++)
	{
		int l = 0;
		if (v[n] < v[i])
		{

			l = LIS(i);

			temp=temp>l ?temp:l;		
		}



	}
	
	return ref=temp + v[n];

	
	


}


int main()
{
	mem.resize(v.size());
	int temp = 0;

	for (int i = 0;i < 1001;i++)
	{
		cache[i] = -1;
	}
	for (int i = 0;i < v.size() - 1;i++)
	{
		int t = LIS(i);
		temp = temp > t ? temp : t;
	}

	cout << temp << endl;
	return 0;
}