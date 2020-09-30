#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	long long n;
	int arr[10000] = { 0 };

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		arr[x - 1]++;
	}

	for (int i = 0; i < 10000; i++)
	{
		if (arr[i] == 0)
			continue;
		else
			for (int j = 0; j < arr[i]; j++)
				cout << i + 1 << "\n";
	}

	return 0;
}