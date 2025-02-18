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

#pragma region ���� ��ȹ��
/*
	���� ��ȹ�� :  ������ ����(��Ÿ�ӿ� �����ϴ�) �� �ƴ� �׳� �������̴� �̸� ������ȹ��
	
	=> ����ȭ�� ���ؼ�

	1. ��ȭ�� ã�� : ���� �κ� ���� : �ݺ����̳� ����Լ��� ����� �� �ֶǷ�
	2. �������� ã�� : �ݺ����̳� ����Լ��� ���� ���� �� �ֵ���
	3. ĳ�� ���� : ������ ã�� ���� ���.
	
	���� �κ� ���� :  ������ ���� ���� ���� ���� ���� �� ���δ�.
	=> ������ ���� ���� �̸� �������.
	





*/
#pragma endregion
//�Ǻ���ġ ����
// �������� : ������ �ݺ����̵� ����Լ��� ���߰ԵǴ� ������.
//f(n)=f(n-1) + f(n-2) ...��ȭ��

vector<__int64> memorization;

int countA = 0;
__int64 Fibonacci(int n)
{
	if (n == 1)
		return 1;
	if (n == 0)
		return 1;
	if (n == 2)
		countA++;
	if (memorization.size() <= n)
	{
		memorization.resize(2 * n);
	}
	if (memorization[n] == 0)
	{
		memorization[n] = (Fibonacci(n - 1) + Fibonacci(n - 2));
	}

	return memorization[n];

}


int main()
{
	memorization.resize(100);
	__int64 start = GetTickCount64();
	cout<<Fibonacci(100)<<endl;
	__int64 end = GetTickCount64();
	cout << countA << endl;
	cout << end - start << endl;
	return 0;
}