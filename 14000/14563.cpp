#include <iostream>
using namespace std;

int main()
{
	int T; cin >> T;
	for (int i = 0; i < T; i++)
	{
		int x; cin >> x;

		int temp = 0;
		for (int j = 1; j < x; j++)
		{
			if (x%j == 0)
				temp += j;
		}

		if (temp == x) cout << "Perfect\n";
		else if (temp > x) cout << "Abundant\n";
		else cout << "Deficient\n";
	}

	return 0;
}