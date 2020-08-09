#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;

	long long dp[65][10];
	memset(dp, 0, sizeof(dp));

	for (int i = 0; i < 10; i++)
	{
		dp[1][i] = 1; dp[2][i] = 10 - i;
	}
	for (int i = 3; i < 65; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = j; k < 10; k++)
			{
				dp[i][j] += dp[i - 1][k];
			}
		}
	}

	for (int i = 0; i < T; i++)
	{
		int n; cin >> n;

		long long answer = 0;
		for (int j = 0; j < 10; j++)
			answer += dp[n][j];

		cout << answer << "\n";
	}

	return 0;
}