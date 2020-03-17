#include <iostream>
using namespace std;

int main()
{
	char chess[8][8];

	for (int r = 0; r < 8; r++)
	{
		for (int c = 0; c < 8; c++)
			cin >> chess[r][c];
	}

	int white = 0;

	for (int r = 0; r < 8; r++)
	{
		for (int c = 0; c < 8; c++)
		{
			if (r % 2 == 0)
			{
				if (c % 2 == 0)
				{
					if (chess[r][c] == 'F')
						white++;
				}
			}
			else
			{
				if (c % 2 == 1)
				{
					if (chess[r][c] == 'F')
						white++;
				}
			}
		}
	}

	cout << white;

	return 0;
}