#include <iostream>
#include <algorithm>
using namespace std;

bool bubble(int arr[],bool flag)
{
	for (int i = 0; i < 4; i++)
	{
		if (arr[i] > arr[i + 1])
		{
			flag = false;
			swap(arr[i], arr[i + 1]);

			for (int i = 0; i < 5; i++)
				cout << arr[i] << " ";
			cout << endl;
		}
	}
	return flag;
}
int main()
{
	int arr[5];
	for (int i = 0; i < 5; i++)
		cin >> arr[i];
	
	while (!bubble(arr, true));

	return 0;
}