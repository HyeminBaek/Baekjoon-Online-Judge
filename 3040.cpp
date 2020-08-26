#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int arr[9]; int sum = 0;
	for (int i = 0; i < 9; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}
	sort(arr, arr + 9);

	int a = 0, b = 0; bool flag = false;
	for (int i = 0; i < 9; i++)
	{
		if (flag) break;
		for (int j = i + 1; j < 9; j++)
		{
			if (sum - arr[i] - arr[j] == 100)
			{
				a = i; b = j;  break;
			}
		}
	}
	for (int i = 0; i < 9; i++)
	{
		if (i == a || i == b) continue;
		cout << arr[i] << '\n';
	}
	return 0;
}