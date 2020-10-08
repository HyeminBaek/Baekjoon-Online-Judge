#include <iostream>
using namespace std;

int main()
{
	int T; cin >> T;
	for (int i = 0; i < T; i++)
	{
		int N; cin >> N;
		int* arr = new int[N];
		int sum = 0;
		for (int j = 0; j < N; j++)
		{
			cin >> arr[j];
			sum += arr[j];
		}
		cout << sum << "\n";
	}

	return 0;
}