#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	int arr[1000]; int dp[1000];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i]; dp[i] = 1;
	}

	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i] < arr[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}
		answer = max(answer, dp[i]);
	}

	cout << answer;

	return 0;
}