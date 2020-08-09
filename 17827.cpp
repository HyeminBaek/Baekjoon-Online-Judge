#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M, V;
	cin >> N >> M >> V;

	vector<int> f;
	for (int i = 0; i < N; i++)
	{
		int x; cin >> x;
		f.push_back(x);
	}

	for (int i = 0; i < M; i++)
	{
		long long K; cin >> K;

		if (K < N)
			cout << f[K] << "\n";
		else
			cout << f[(V - 1) + (K - V + 1) % (N - V + 1)] << "\n";
	}
	return 0;
}