#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	char mirror[100][100];
	char magic[100][100];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> mirror[i][j];
	}

	int k;
	cin >> k;

	switch (k)
	{
	case 1:
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				cout << mirror[i][j];
			cout << "\n";
		}
		break;
	case 2:
		for (int i = 0; i < n; i++)
		{
			for (int j = n - 1, c = 0; j > -1, c < n; j--, c++)
				magic[i][c] = mirror[i][j];
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				cout << magic[i][j];
			cout << "\n";
		}
		break;
	case 3:
		for (int i = n - 1, r = 0; i > 0, r < n; i--, r++)
		{
			for (int j = 0; j < n; j++)
				magic[r][j] = mirror[i][j];
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				cout << magic[i][j];
			cout << "\n";
		}
		break;
	}
	return 0;
}