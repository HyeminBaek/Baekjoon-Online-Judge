#include <iostream>
using namespace std;

int main()
{
	long long N; cin >> N;

	for (long long i = 1; i <= N; i++)
	{
		if (1 + 3 * i*(i - 1) == N)
		{
			cout << i; break;
		}
		else if (1 + 3 * i*(i - 1) < N)
		{
			if (1 + 3 * i*(i + 1) >= N)
			{
				cout << i + 1; break;
			}
		}
	}

	return 0;
}