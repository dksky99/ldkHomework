#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
#include<stack>
#include<queue>
#include<algorithm>
#include<Windows.h>

#include "BST.h"
using namespace std;

#pragma region �����ϱ�
/*

	�����ϱ� :  ��ȭ�ϴ� �� +1, +2, +3
	n ���� �ϰ� �ʹ�
	�� �� ���� �� �ִ� ����� ��
	



	1: 1
	2 : 1 1 ,2
	3 : 1 1 1 ,2 1 ,1 2, 3
	4 : 1 1 1 1 , 1 1 2 , 1 2 1 , 2 1 1 ,2 2,3 1,1 3
	5: 1 1 1 1 1, 1 1 1 2 ,1 1 2 1,1 2 1 1,2 1 1 1,2 2 1,2 1 2,1 2 2,3 2,2 3,3 1 1,1 3 1,1 1 3
	4=7
	5=13
	8= 7n1 6n2 5n3


	

	

	

	
*/
#pragma endregion
vector<int> mem;
int Inchent(int n)
{
	
	if (n < 0)
		return 0;
	if (n == 0)
		return 1;
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	if (n == 3)
		return 4;

	int& t = mem[n];
	if (t != -1)
	{
		return mem[n];
	}

	int temp = Inchent(n - 1) + Inchent(n - 3) + Inchent(n - 2);
	//temp *= 2;
	return t=temp;


	



}

int main()
{
	mem.resize(3000, -1);

	cout << Inchent(6) << endl;
	
	return 0;
}