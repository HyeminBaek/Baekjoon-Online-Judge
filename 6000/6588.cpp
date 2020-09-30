#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//에라토스테네스의 체
	bool isPrime[1000001];
	memset(isPrime, true, sizeof(isPrime));

	for (int i = 2; i*i < 1000001; i++)
	{
		if (isPrime[i])
		{
			for (int j = i * i; j < 1000001; j += i)
				isPrime[j] = false;
		}
	}

	int n;
	while (cin >> n)
	{
		if (n == 0) break;

		bool flag = false;
		for (int i = 3; i <= n; i++)
		{
			if (isPrime[i] && isPrime[n - i])
			{
				cout << n << " = " << i << " + " << n - i << "\n";
				flag = true; break;
			}
		}
		if (!flag)	cout << "Goldbach's conjecture is wrong.\n";
	}

	return 0;
}