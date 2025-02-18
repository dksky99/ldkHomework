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

#pragma region 동적 계획법
/*
	동적 계획법 :  기존의 동적(런타임에 뭔갈하는) 이 아닌 그냥 멋져보이는 이름 동적계획법
	
	=> 최적화를 위해서

	1. 점화식 찾기 : 최적 부분 구조 : 반복문이나 재귀함수를 사용할 수 있또록
	2. 기저사항 찾기 : 반복문이나 재귀함수가 끝을 맞을 수 있도록
	3. 캐쉬 설계 : 이전에 찾은 값을 기록.
	
	최적 부분 구조 :  이전에 구한 답이 다음 답을 구할 때 쓰인다.
	=> 이전에 구한 답을 미리 적어놓자.
	





*/
#pragma endregion
//피보나치 수열
// 기저사항 : 언젠가 반복문이든 재귀함수든 멈추게되는 끝지점.
//f(n)=f(n-1) + f(n-2) ...점화식

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