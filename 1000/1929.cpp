#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int M, N; cin >> M >> N;

	for (int i = M; i <= N; i++)
	{
		bool flag = false;
		for (int j = 2; j <= sqrt(i); j++)
		{
			if (i%j == 0)
			{
				flag = true; break;
			}
		}
		if (!flag&&i!=1) cout << i << "\n";
	}

	return 0;
}