#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, k; cin >> n >> k;

	int arr[101];
	int dp[100001];
	memset(dp, 10000, sizeof(dp));
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		dp[arr[i]] = 1;
	}
	sort(arr, arr + n);
	if (arr[0] > k)
	{
		cout << -1; return 0;
	}
	for (int i = arr[0] + 1; i <= k; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i >= arr[j])
			{
				dp[i] = min(dp[i], dp[arr[j]] + dp[i - arr[j]]);
			}
		}
	}
	cout << dp[k];

	return 0;
}