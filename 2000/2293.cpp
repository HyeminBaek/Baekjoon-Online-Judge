#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	int dp[10001] = {};
	int* arr = new int[n];

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	dp[0] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k + 1; j++)
		{
			if (j >= arr[i])
				dp[j] += dp[j - arr[i]];
		}
	}

	cout << dp[k];

	return 0;
}