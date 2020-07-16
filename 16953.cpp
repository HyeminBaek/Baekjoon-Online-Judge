#include <iostream>
using namespace std;

int main()
{
	long long A, B;
	cin >> A >> B;

	long long answer = 0;
	while (1)
	{
		if (B == A)
			break;
		if (B < A)
		{
			answer = -2; break;
		}

		if (B % 2 == 0)
		{
			B /= 2; answer++;
		}
		else
		{
			if (B % 10 == 1)
			{
				B--; B /= 10; answer++;
			}
			else
			{
				answer = -2; break;
			}
		}
	}

	cout << answer + 1;

	return 0;
}