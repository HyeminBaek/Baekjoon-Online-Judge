#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;

	int d[11] = {};
	d[0] = d[1] = 1;
	for (int i = 2; i < 11; i++)
	{
		d[i] += d[i - 1];
		d[i] += d[i - 2];
		if (i >= 3)
			d[i] += d[i - 3];
	}
	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;
		cout << d[n] << "\n";
	}

	return 0;
}