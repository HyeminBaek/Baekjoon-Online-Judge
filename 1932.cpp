#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int tri[501][501];
	int d[501][501] = { 0, };

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cin >> tri[i][j];
		}
	}

	d[0][0] = tri[0][0];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			d[i + 1][j] = max(d[i + 1][j], d[i][j] + tri[i + 1][j]);
			if (j + 1 != n)
				d[i + 1][j + 1] = max(d[i + 1][j + 1], d[i][j] + tri[i + 1][j + 1]);
		}
	}

	int maxi = 0;
	for (int i = 0; i < n; i++)
		maxi = max(maxi, d[n - 1][i]);

	cout << maxi;

	return 0;
}