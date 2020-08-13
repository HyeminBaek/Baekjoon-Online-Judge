#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;
	for (int i = 0; i < T; i++)
	{
		int N, M; cin >> N >> M;
		int* roulette = new int[N];

		long long x = 0, y = 0;
		for (int j = 0; j < M; j++)
		{
			int c; cin >> c;
			x = x * 10 + c;
		}
		for (int j = 0; j < M; j++)
		{
			int c; cin >> c;
			y = y * 10 + c;
		}
		for (int j = 0; j < N; j++)
			cin >> roulette[j];

		int answer = 0;
		for (int j = 0; j < N; j++)
		{
			long long temp = 0;
			for (int k = 0; k < M; k++)
			{
				if (j + k < N)
					temp = temp * 10 + roulette[j + k];
				else
					temp = temp * 10 + roulette[j + k - N];
			}
			if (temp >= x && temp <= y)
				answer++;
		}
		cout << answer << "\n";
	}

	return 0;
}