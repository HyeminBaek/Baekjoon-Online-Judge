#include <iostream>
using namespace std;

int min(int arr[], int SIZE);
int main()
{
	int T; cin >> T;

	const int SIZE = 7;
	for (int i = 0; i < T; i++)
	{
		int arr[SIZE];
		int even[SIZE]; int idx = 0, sum = 0;
		for (int j = 0; j < SIZE; j++)
		{
			cin >> arr[j];
			if (arr[j] % 2 == 0)
			{
				even[idx++] = arr[j];
				sum += arr[j];
			}
		}
		cout << sum<<" "<<min(even, idx) << endl;
	}

	return 0;
}
int min(int arr[], int SIZE)
{
	int answer = arr[0];
	for (int i = 1; i < SIZE; i++)
		answer = (answer > arr[i]) ? arr[i] : answer;

	return answer;
}