#include <iostream>
#include <algorithm>
using namespace std;

/*
TEST CASE
INPUT:
5
10 90 20 80 100
OUTPUT:210
*/
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	int arr[1000]; 
	int dp[1000]; //dp[i] = 인덱스 i까지의 증가하는 배열의 max 값
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i]; dp[i] = arr[i];
	}
	
	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j])
				dp[i] = max(dp[i], dp[j] + arr[i]);
		}
		answer = max(answer, dp[i]);
	}

	cout << answer<<"\n";

	return 0;
}