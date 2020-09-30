#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
	int N; cin >> N;

	int dp[100001] = { 0, };
	for (int i = 1; i*i <= N; i++)
		dp[i*i] = 1;

	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j < sqrt(i); j++)
		{
			if (dp[i] == 0)
				dp[i] = dp[j*j] + dp[i - j * j];
			else
				dp[i] = min(dp[i], dp[j*j] + dp[i - j * j]);
		}
	}
	cout << dp[N];

	return 0;
}