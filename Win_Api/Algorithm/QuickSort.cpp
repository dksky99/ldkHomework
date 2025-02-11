#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

#pragma region 퀵 정렬
/*
	
	퀵정렬

	피봇: 기준점. 

	레프트 : 피봇보다 작으면 넘어가고 큰애가 나오면 멈춤
	롸이트 : 피봇보다 크면 넘어가고 작은애가 나오면 멈춤

	레프트와 라이트가 다 멈췄는데 아직 교차하지 못했다면 두 수를 스왑

	레프트와 롸이트가 교차하면 분할이 종료. 
	롸이트 값과 피봇을 스왑. 롸이트 위치를 반환.

	이 반환된 위치를 기준으로 다시 두개의 퀵정렬을 실행.
	이전 정렬로 완전히 정해진 구 피봇의 위치를 제외한 나머지 부분을 정렬실행하여
	재귀함수 형태로 실행. 
	하다가 원소가 하나인 배열을 정렬을 시도하면 정렬을 완료. 
	모든 재귀 함수가 실행이 종료되면 정렬이 완료되어있음.

	//시간복잡도 n*log2(n)
	피봇이 제일 왼쪽에 있는 제자리에있는 애면 최악의 속도가 나옴

	최고의 속도는 피봇이 정확히 중앙을 가를때 최고의 속도가 나옴.



*/
#pragma endregion


int Partition(vector<int>& v, int left, int right)
{
	//기준 : 제일 왼쪽의 수
	int pivot = v[left];
	
	// 피봇 이후 다음수
	int lowIndex = left + 1;
	//제일 오른쪽 수
	int highIndex = right;
	while (true)
	{
		//레프트와 롸이트가 역전됨. 자리를 찾았다.
		if (lowIndex > highIndex)
		{
			break;
		}

		//래프트가 가르키는 값이 피봇보다 작으면 오른쪽으로 나아감
		if (lowIndex <= right && pivot > v[lowIndex])
		{

			lowIndex++;
		}

		//롸이트가 가르키는 값이 피봇보다 크면 왼쪽으로 나아감.
		if (highIndex >= left && pivot < v[highIndex])
		{
			highIndex--;
		}
		
		//만약 교차 전에 멈췄을때를 위해 둘의 값을 스왑해주면 계속 진행 할 수 있게된다.
		if (lowIndex < highIndex)
		{
			std::swap(v[lowIndex], v[highIndex]);
		}

	}
	//찾은 자리와 피봇을 교체
	std::swap(v[highIndex], v[left]);

	//찾은 자리의 인덱스를 반환.
	return highIndex;

}
void QuickSort(vector<int>& v, int left, int right)
{
	//기저사항 : 교차 : 정렬이 완료됨.
	if (left > right)
	{
		return;
	}
	
	//분할. 
	int pivotIndex = Partition(v, left, right);
	cout << left << "~"<<pivotIndex - 1 << endl;

	//제일 왼쪽부터 분할된 기준점의 왼쪽
	QuickSort(v, left, pivotIndex - 1);
	//기준점의 오른쪽부터 제일 오른쪽까지.
	QuickSort(v, pivotIndex+1,right);



}



int main()
{
	vector<int> v = { 55,30,15,100,1,5,70,120 };

	
	//시간복잡도 n*log2(n)
	QuickSort(v, 0, v.size() - 1);



	return 0;
}