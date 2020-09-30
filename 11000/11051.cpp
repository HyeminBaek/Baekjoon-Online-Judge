#include <iostream>
using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;

	int dp[1001][1001] = { 0, };

	for (int i = 1; i <= N; i++)
	{
		dp[i][0] = 1; dp[i][1] = i;
	}
	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j <= K; j++)
		{
			if (dp[i][j] == 0)
				dp[i][j] = ((dp[i - 1][j] % 10007) + (dp[i - 1][j - 1] % 10007)) % 10007;
		}
	}

	cout << dp[N][K] % 10007;

	return 0;
}