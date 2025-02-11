#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

#pragma region 병합 정렬
/*

	분할 정복 알고리즘 : 그대로 해결할 수 없는 문제를 작은 문제로 분할하여 해결하는 방식.

	안전한 정렬 : 

	퀵정렬의 경우 같은 값을 갖는 원소가 2개이상있을경우 두 원소의 순서가 섞일 가능성이있음
	병합 정렬은 같은 값을 갖는 두원소의 순서가 지켜진다.

	중앙을 기준으로 자르고
	더이상 나눠지지 않을때까지 갈기갈기 잘라서 한개짜리 배열을 기존 배열의 원소 수 만큼 만들고 
	하나씩 비교해가며 작은 수가 왼쪽에 오도록 합쳐간다.
	두 배열의 제일 앞 원소들을 비교해 하나씩 임시 배열에 넣어서 반환하여 배열을 정렬해가면된다.
	왼쪽배열엔 레프트가 남은 원소중 최소값을 가르키고 오른족 배열엔 롸이트가 최소값을 가르킨다.


	임시배열을 만든다는것이 단점이다. 
	복사비용이 많이듬. 


	힙정렬: 모든 값을 정렬하지 않고 상위 몇명만 뽑아낼때 좋음
	병합정렬 : 동일 값을 가진 원소를 섞일일 없이 안전히 정렬하고자 할때




*/
#pragma endregion


//정복 결합
void MergeResult(vector<int>& v, int left, int mid, int right)
{
	//처음에 들어왔을때는 제일 잘게 쪼개진 상태에서 시작.

	vector<int>temp;

	//레프트 인덱스는 left~ mid까지
	int leftIndex = left;
	//롸이트 인덱스는 mid+1~right까지
	int rightIndex = mid + 1;
	while (true)
	{
		//두 배열중 하나가 이미 전부 소모됬을때
		if (leftIndex > mid || rightIndex > right)
			break;

		//두 배열의 최소값중 더 작은값을 입력
		if (v[leftIndex] <= v[rightIndex])
		{
			temp.push_back(v[leftIndex++]);
		}
		else
		{
			temp.push_back(v[rightIndex++]);

		}


	}

	//남은 배열의 원소를 전부 임시 배열에 넣음

	//right쪽이 남아있다.
	if (leftIndex > mid)
	{
		while (rightIndex <= right)
		{
			temp.push_back(v[rightIndex++]);

		}
	}

	//left쪽이 남아있다
	if (rightIndex > right)
	{
		while (leftIndex <= mid)
		{
			temp.push_back(v[leftIndex++]);

		}
	}
	//정렬이 완료되어 원본에 정렬된 값을 복사해줌.
	for (int i = 0;i < temp.size();i++)
	{
		v[left + i] = temp[i];
	}




}

//분할 
void MergeSort(vector<int>& v, int left, int right)
{
	//레프트가 롸이트와 같아지면 반환. : 기저사항. 원소가 하나다.
	if (left >= right)
		return;
	int mid = (left + right) / 2;

	//재귀 함수 형식. 최상위에서부터 배열의 원소의 수가 하나만남을때까지 분할한다.
	MergeSort(v, left, mid);
	MergeSort(v, mid + 1, right);


	//병합
	MergeResult(v, left, mid, right);

}
int main()
{

	vector<int> v = { 55,30,15,100,1,5,70,120 ,30};


	MergeSort(v, 0, v.size() - 1);


	//퀵 정렬 : 빠르다
	sort(v.begin(), v.end());

	//힙정렬 : 제일 위의 3개만 최대값으로 정렬. 일부만 정렬해서 볼때 효과적
	partial_sort(v.begin(), v.begin() + 3, v.end());

	//병합정렬 : 동일한 값의 순서를 뒤섞고 싶지 않을때 사용. 안전한 정렬
	stable_sort(v.begin(), v.end());

	return 0;
}






