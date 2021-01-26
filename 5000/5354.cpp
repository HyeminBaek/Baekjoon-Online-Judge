#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t; cin >> t;
	for (t; t > 0; t--)
	{
		int x; cin >> x;
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < x; j++)
			{
				if (i == 0 || i == x - 1)
					cout << '#';
				else if (j == 0 || j == x - 1)
					cout << '#';
				else cout << 'J';
			}
			cout << "\n";
		}
		cout << "\n";
	}

	return 0;
}