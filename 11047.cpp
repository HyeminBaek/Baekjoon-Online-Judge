#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, K; cin >> N >> K;
	int* coin = new int[N];
	for (int i = 0; i < N; i++)
		cin >> coin[i];

	int answer = 0;
	for (int i = N - 1; i >= 0; i--)
	{
		if (K == 0) break;
		if (coin[i] > K) continue;
		else
		{
			answer += K / coin[i];
			K %= coin[i];
		}
	}
	cout << answer;

	return 0;
}