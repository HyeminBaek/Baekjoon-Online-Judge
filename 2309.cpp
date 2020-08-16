#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int nanjang[9]; int sum = 0;
	for (int i = 0; i < 9; i++)
	{
		cin >> nanjang[i];
		sum += nanjang[i];
	}

	sort(nanjang, nanjang + 9);
	int x = 0, y = 0;
	for (int i = 0; i < 9; i++)
	{
		int temp = sum;
		temp -= nanjang[i];
		for (int j = i + 1; j < 9; j++)
		{
			if (temp - nanjang[j] == 100)
			{
				x = i; y = j; break;
			}
		}
	}
	for (int i = 0; i < 9; i++)
	{
		if (i == x || i == y) continue;
		cout << nanjang[i] << "\n";
	}

	return 0;
}