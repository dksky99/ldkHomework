#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

#pragma region ���� ����
/*

	���� ���� �˰��� : �״�� �ذ��� �� ���� ������ ���� ������ �����Ͽ� �ذ��ϴ� ���.

	������ ���� : 

	�������� ��� ���� ���� ���� ���Ұ� 2���̻�������� �� ������ ������ ���� ���ɼ�������
	���� ������ ���� ���� ���� �ο����� ������ ��������.

	�߾��� �������� �ڸ���
	���̻� �������� ���������� ���Ⱕ�� �߶� �Ѱ�¥�� �迭�� ���� �迭�� ���� �� ��ŭ ����� 
	�ϳ��� ���ذ��� ���� ���� ���ʿ� ������ ���İ���.
	�� �迭�� ���� �� ���ҵ��� ���� �ϳ��� �ӽ� �迭�� �־ ��ȯ�Ͽ� �迭�� �����ذ���ȴ�.
	���ʹ迭�� ����Ʈ�� ���� ������ �ּҰ��� ����Ű�� ������ �迭�� ����Ʈ�� �ּҰ��� ����Ų��.


	�ӽù迭�� ����ٴ°��� �����̴�. 
	�������� ���̵�. 


	������: ��� ���� �������� �ʰ� ���� ��� �̾Ƴ��� ����
	�������� : ���� ���� ���� ���Ҹ� ������ ���� ������ �����ϰ��� �Ҷ�




*/
#pragma endregion


//���� ����
void MergeResult(vector<int>& v, int left, int mid, int right)
{
	//ó���� ���������� ���� �߰� �ɰ��� ���¿��� ����.

	vector<int>temp;

	//����Ʈ �ε����� left~ mid����
	int leftIndex = left;
	//����Ʈ �ε����� mid+1~right����
	int rightIndex = mid + 1;
	while (true)
	{
		//�� �迭�� �ϳ��� �̹� ���� �Ҹ�������
		if (leftIndex > mid || rightIndex > right)
			break;

		//�� �迭�� �ּҰ��� �� �������� �Է�
		if (v[leftIndex] <= v[rightIndex])
		{
			temp.push_back(v[leftIndex++]);
		}
		else
		{
			temp.push_back(v[rightIndex++]);

		}


	}

	//���� �迭�� ���Ҹ� ���� �ӽ� �迭�� ����

	//right���� �����ִ�.
	if (leftIndex > mid)
	{
		while (rightIndex <= right)
		{
			temp.push_back(v[rightIndex++]);

		}
	}

	//left���� �����ִ�
	if (rightIndex > right)
	{
		while (leftIndex <= mid)
		{
			temp.push_back(v[leftIndex++]);

		}
	}
	//������ �Ϸ�Ǿ� ������ ���ĵ� ���� ��������.
	for (int i = 0;i < temp.size();i++)
	{
		v[left + i] = temp[i];
	}




}

//���� 
void MergeSort(vector<int>& v, int left, int right)
{
	//����Ʈ�� ����Ʈ�� �������� ��ȯ. : ��������. ���Ұ� �ϳ���.
	if (left >= right)
		return;
	int mid = (left + right) / 2;

	//��� �Լ� ����. �ֻ����������� �迭�� ������ ���� �ϳ������������� �����Ѵ�.
	MergeSort(v, left, mid);
	MergeSort(v, mid + 1, right);


	//����
	MergeResult(v, left, mid, right);

}
int main()
{

	vector<int> v = { 55,30,15,100,1,5,70,120 ,30};


	MergeSort(v, 0, v.size() - 1);


	//�� ���� : ������
	sort(v.begin(), v.end());

	//������ : ���� ���� 3���� �ִ밪���� ����. �Ϻθ� �����ؼ� ���� ȿ����
	partial_sort(v.begin(), v.begin() + 3, v.end());

	//�������� : ������ ���� ������ �ڼ��� ���� ������ ���. ������ ����
	stable_sort(v.begin(), v.end());

	return 0;
}






