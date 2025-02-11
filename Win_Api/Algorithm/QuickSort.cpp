#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

#pragma region �� ����
/*
	
	������

	�Ǻ�: ������. 

	����Ʈ : �Ǻ����� ������ �Ѿ�� ū�ְ� ������ ����
	����Ʈ : �Ǻ����� ũ�� �Ѿ�� �����ְ� ������ ����

	����Ʈ�� ����Ʈ�� �� ����µ� ���� �������� ���ߴٸ� �� ���� ����

	����Ʈ�� ����Ʈ�� �����ϸ� ������ ����. 
	����Ʈ ���� �Ǻ��� ����. ����Ʈ ��ġ�� ��ȯ.

	�� ��ȯ�� ��ġ�� �������� �ٽ� �ΰ��� �������� ����.
	���� ���ķ� ������ ������ �� �Ǻ��� ��ġ�� ������ ������ �κ��� ���Ľ����Ͽ�
	����Լ� ���·� ����. 
	�ϴٰ� ���Ұ� �ϳ��� �迭�� ������ �õ��ϸ� ������ �Ϸ�. 
	��� ��� �Լ��� ������ ����Ǹ� ������ �Ϸ�Ǿ�����.

	//�ð����⵵ n*log2(n)
	�Ǻ��� ���� ���ʿ� �ִ� ���ڸ����ִ� �ָ� �־��� �ӵ��� ����

	�ְ��� �ӵ��� �Ǻ��� ��Ȯ�� �߾��� ������ �ְ��� �ӵ��� ����.



*/
#pragma endregion


int Partition(vector<int>& v, int left, int right)
{
	//���� : ���� ������ ��
	int pivot = v[left];
	
	// �Ǻ� ���� ������
	int lowIndex = left + 1;
	//���� ������ ��
	int highIndex = right;
	while (true)
	{
		//����Ʈ�� ����Ʈ�� ������. �ڸ��� ã�Ҵ�.
		if (lowIndex > highIndex)
		{
			break;
		}

		//����Ʈ�� ����Ű�� ���� �Ǻ����� ������ ���������� ���ư�
		if (lowIndex <= right && pivot > v[lowIndex])
		{

			lowIndex++;
		}

		//����Ʈ�� ����Ű�� ���� �Ǻ����� ũ�� �������� ���ư�.
		if (highIndex >= left && pivot < v[highIndex])
		{
			highIndex--;
		}
		
		//���� ���� ���� ���������� ���� ���� ���� �������ָ� ��� ���� �� �� �ְԵȴ�.
		if (lowIndex < highIndex)
		{
			std::swap(v[lowIndex], v[highIndex]);
		}

	}
	//ã�� �ڸ��� �Ǻ��� ��ü
	std::swap(v[highIndex], v[left]);

	//ã�� �ڸ��� �ε����� ��ȯ.
	return highIndex;

}
void QuickSort(vector<int>& v, int left, int right)
{
	//�������� : ���� : ������ �Ϸ��.
	if (left > right)
	{
		return;
	}
	
	//����. 
	int pivotIndex = Partition(v, left, right);
	cout << left << "~"<<pivotIndex - 1 << endl;

	//���� ���ʺ��� ���ҵ� �������� ����
	QuickSort(v, left, pivotIndex - 1);
	//�������� �����ʺ��� ���� �����ʱ���.
	QuickSort(v, pivotIndex+1,right);



}



int main()
{
	vector<int> v = { 55,30,15,100,1,5,70,120 };

	
	//�ð����⵵ n*log2(n)
	QuickSort(v, 0, v.size() - 1);



	return 0;
}