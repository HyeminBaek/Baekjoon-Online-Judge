#include <iostream>
#include <cstring>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	long long dp[1001][10]; 
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < 10; i++)
		dp[1][i] = 1;

	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = j; k < 10; k++)
			{
				dp[i][j] += dp[i - 1][k];
				dp[i][j] %= 10007;
			}
		}
	}
	
	long long sum = 0;
	for (int i = 0; i < 10; i++)
	{
		sum += dp[N][i];
		sum %= 10007;
	}

	cout << sum % 10007;

	return 0;
}