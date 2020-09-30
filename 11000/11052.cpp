#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	int* price = new int[N + 1];
	int dp[1001]; memset(dp, 0, sizeof(dp));
	for (int i = 1; i < N + 1; i++)
	{
		cin >> price[i]; dp[i] = price[i];
	}

	for (int i = 2; i <= N; i++)
	{
		for (int j = i - 1; j >= i / 2; j--)
		{
			dp[i] = max(dp[i], dp[j] + dp[i - j]);
		}
	}
	cout << dp[N];

	return 0;
}