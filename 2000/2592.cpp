#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int sum = 0, maxNum = 0, maxIdx = -1;
	int arr[101] = { 0, };

	for (int i = 0; i < 10; i++)
	{
		int x; cin >> x;
		sum += x;
		arr[x / 10]++;
		if (maxNum < arr[x / 10])
		{
			maxNum = arr[x / 10];
			maxIdx = x;
		}
	}

	cout << sum / 10 << "\n" << maxIdx;

	return 0;
}