#include <iostream>
using namespace std;

int main()
{
	long long D[101];
	D[0] = 1; D[1] = 1; D[2] = 1; D[3] = D[1] + D[2]; D[4] = D[3];

	for (int i = 5; i < 101; i++)
		D[i] = D[i - 1] + D[i - 5];

	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;

		cout << D[n - 1] << "\n";
	}

	return 0;
}