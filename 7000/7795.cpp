#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;
	for (T; T > 0; T--)
	{
		int N, M; cin >> N >> M;

		int answer = 0;
		vector<int> A, B;
		for (int i = 0; i < N; i++)
		{
			int x; cin >> x;
			A.push_back(x);
		}
		for (int i = 0; i < M; i++)
		{
			int x; cin >> x;
			B.push_back(x);
		}
		sort(B.begin(), B.end());

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (A[i] <= B[j]) break;
				answer++;
			}
		}
		cout << answer << "\n";
	}

	return 0;
}