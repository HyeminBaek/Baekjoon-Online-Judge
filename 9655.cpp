#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	int dp[1001];
	memset(dp, -1, sizeof(dp));
	dp[1] = 1; dp[3] = 1;
	for (int i = 1; i < N; i++)
	{
		if (i + 3 <= N)
		{
			if (dp[i + 3] != -1)
				dp[i + 3] = min(dp[i + 3], dp[i] + 1);
			else
				dp[i + 3] = dp[i] + 1;
		}
		if (i + 1 <= N)
		{
			if (dp[i + 1] != -1)
				dp[i + 1] = min(dp[i + 1], dp[i] + 1);
			else
				dp[i + 1] = dp[i] + 1;
		}
	}

	if (dp[N] % 2 == 0) cout << "CY";
	else cout << "SK";

	return 0;
}