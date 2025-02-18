#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
#include<stack>
#include<queue>
#include<algorithm>

using namespace std;


int cache[301][301] = { 0, };

int N = 0;
vector<int> v;
int DP(int prev, int n)
{

	if (n >= N)
		return -20000;
	int& ref = cache[prev][n];
	if (ref != 0)
		return ref;

	ref = v[n];

	if (n != prev + 1)
	{
		ref = max(ref, DP(n, n + 1) + v[n]);
	}

	ref = max(ref, DP(n, n + 2) + v[n]);

	return ref;

}
void Input()
{

	cin >> N;
	for (int i = 0;i < N;i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
}

int main()
{
	Input();
	reverse(v.begin(), v.end());
	cout << DP(0, 0) << endl;



}