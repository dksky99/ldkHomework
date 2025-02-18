#include<iostream>
#include<vector>

using namespace std;

int N;
int M;
int v[100001] = {0,};




void Input()
{

	cin >> N;
	cin >> M;

	v[0] = 0;
	for (int i = 1;i <= N;i++)
	{
		int temp;
		cin >> temp;
		v[i]=v[i-1]+temp;
	}
	for (int i = 0;i < M;i++)
	{
		int start, end;
		cin >> start>> end;

		cout << v[end] - v[start-1]<<"\n";


	}
}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Input();

	return 0;


}