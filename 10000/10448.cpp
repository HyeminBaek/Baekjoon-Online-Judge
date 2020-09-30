#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;
	for (int i = 0; i < T; i++)
	{
		int n; cin >> n;

		bool flag = false;
		for (int j = 1; j * (j + 1) < 2 * n; j++)
		{
			int T1 = j * (j + 1) / 2;
			if (flag || T1 > n) break;

			for (int k = j; k * (k + 1) < 2 * n; k++)
			{
				int T2 = k * (k + 1) / 2;
				if (flag || T1 + T2 > n) break;
				for (int l = k; l * (l + 1) < 2 * n; l++)
				{
					int T3 = l * (l + 1) / 2;
					if (T1 + T2 + T3 > n) break;
					if (T1 + T2 + T3 == n)
					{
						flag = true; break;
					}
				}
			}
		}
		cout << flag << "\n";
	}

	return 0;
}