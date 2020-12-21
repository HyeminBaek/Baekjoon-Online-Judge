#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	int R = a % b;
	int G = b;

	if (R == 0)
		return b;
	else
	{
		while (R > 0)
		{
			if (G%R == 0) return R;
			else
			{
				int temp = G;
				G = R;
				R = temp % R;
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t; cin >> t;
	for (int T = 0; T < t; T++)
	{
		int n; cin >> n;
		int* arr = new int[n];
		for (int i = 0; i < n; i++)
			cin >> arr[i];

		long long sum = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (arr[i] > arr[j])
					sum += gcd(arr[i], arr[j]);
				else
					sum += gcd(arr[j], arr[i]);
			}
		}

		cout << sum << "\n";
	}

	return 0;
}