#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int* arr = new int[n];
	int* dp = new int[n];

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	dp[0] = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (dp[i - 1] + arr[i] > arr[i])
			dp[i] = dp[i - 1] + arr[i];
		else
			dp[i] = arr[i];
	}

	sort(dp, dp + n);

	cout << dp[n - 1];

	return 0;
}