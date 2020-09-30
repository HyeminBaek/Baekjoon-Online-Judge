#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	long long X, Y;
	cin >> X >> Y;

	long long dif = Y - X;

	if (dif < 3)
	{
		cout << dif; return 0;
	}
	for (long long mid = 1; mid < dif; mid++)
	{
		long long temp = dif - (mid * (mid + 1));
		if (temp <= 1)
		{
			cout << 2 * mid; break;
		}
		else if (temp > 1 && temp <= mid + 1)
		{
			cout << 2 * mid + 1; break;
		}
	}

	return 0;
}