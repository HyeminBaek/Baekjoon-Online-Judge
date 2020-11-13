#include <iostream>
using namespace std;

int main()
{
	const int SIZE = 6;
	int arr[SIZE];

	int sum = 0;
	for (int i = 0; i < SIZE; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}
	int min = arr[0];
	for (int i = 0; i < 4; i++)
		min = (min > arr[i]) ? arr[i] : min;

	sum -= min;
	min = (arr[4] > arr[5]) ? arr[5] : arr[4];
	sum -= min;

	cout << sum;

	return 0;
}