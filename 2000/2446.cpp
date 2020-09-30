#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int n, blank = 0;
	cin >> n;

	for (int i = n; i > 0; i--)
	{
		cout << setw(++blank);

		for (int j = 0; j < 2 * i - 1; j++)
			cout << '*';

		cout << "\n";
	}
	for (int i = 2; i <= n; i++)
	{
		cout << setw(--blank);

		for (int j = 0; j < 2 * i - 1; j++)
			cout << '*';

		cout << "\n";
	}

	return 0;
}