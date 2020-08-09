#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	long long dp[1001][1001];
	memset(dp, 0, sizeof(dp));

	int n, m;
	cin >> n >> m;

	dp[1][1] = 1; dp[1][2] = 1; dp[2][1] = 1;
	if (n == 1 && m == 1)
	{
		cout << dp[1][1]; return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (dp[i][j] == 0)
			{
				dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]
					+ dp[i - 1][j - 1]) % 1000000007;
			}
		}
	}

	cout << dp[n][m] % 1000000007;

	return 0;
}