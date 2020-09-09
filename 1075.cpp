#include <iostream>
using namespace std;

int main()
{
	long long n, f; cin >> n >> f;

	n -= n % 100;

	for (int i = 0; i <= 99; i++)
	{
		if ((n + i) % f == 0)
		{
			if (i >= 10) cout << i;
			else cout << '0' << i;
			break;
		}
	}
	return 0;
}