#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	if (N == 0 || N % 2 == 1) cout << 0;
	else
	{
		int dp[31] = { 0, };
		dp[0] = 1;
		for (int i = 2; i <= N; i += 2)
		{
			dp[i] = dp[i - 2] * 3;
			for (int j = 4; j <= i; j += 2)
				dp[i] += dp[i - j] * 2;
		}
		cout << dp[N];
	}

	return 0;
}