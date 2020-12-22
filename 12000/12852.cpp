#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;

	int dp[1000001] = { 0, };
	int answer[1000001] = { 0, };

	dp[1] = 0;
	for (int temp = 2; temp <= N; temp++)
	{
		if (dp[temp] == 0 || dp[temp] > dp[temp-1] + 1)
		{
			dp[temp] = dp[temp-1] + 1;
			answer[temp] = temp - 1;
		}
		if (temp % 2 == 0)
		{
			if (dp[temp] == 0 || dp[temp] > dp[temp/2] + 1)
			{
				dp[temp] = dp[temp/2] + 1;
				answer[temp] = temp / 2;
			}
		}
		if (temp % 3 == 0)
		{
			if (dp[temp] == 0 || dp[temp] > dp[temp/3] + 1)
			{
				dp[temp] = dp[temp/3] + 1;
				answer[temp] = temp / 3;
			}
		}
	}
	cout << dp[N] << "\n";
	int idx = N;
	while (1)
	{
		cout << idx << ' ';
		if (idx == 1) break;
		idx = answer[idx];
	}

	return 0;
}

