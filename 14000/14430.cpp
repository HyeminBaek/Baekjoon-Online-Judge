#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int M, N; cin >> M >> N;
	int arr[301][301];
	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= N; j++)
			cin >> arr[i][j];
	}

	int dp[301][301] = { 0, };
	dp[1][1] = arr[1][1];
	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (i + 1 <= M)
			{
				dp[i + 1][j] = (dp[i + 1][j] < dp[i][j] + arr[i + 1][j]) ? dp[i][j] + arr[i + 1][j] : dp[i + 1][j];
			}
			if (j + 1 <= N)
			{
				dp[i][j + 1] = (dp[i][j + 1] < dp[i][j]+arr[i][j + 1]) ? dp[i][j]+ arr[i][j + 1] : dp[i][j + 1];
			}
		}
	}
	int max = 0;
	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= N; j++)
			max = (max < dp[i][j]) ? dp[i][j] : max;
	}
	cout << max;

	return 0;
}