#include <iostream>
using namespace std;

int main()
{
	int N, M; cin >> N >> M;
	int arr[2][1000];

	for (int i = 0; i < 2; i++)
	{
		if (i == 0)
		{
			for (int j = 0; j < N; j++)
				cin >> arr[i][j];
		}
		else
		{
			for (int j = 0; j < M; j++)
				cin >> arr[i][j];
		}
	}

	int max1 = arr[0][0], max2 = arr[1][0];
	for (int i = 1; i < N; i++)
		max1 = (max1 < arr[0][i]) ? arr[0][i] : max1;
	for(int i=1;i<M;i++)
		max2 = (max2 < arr[1][i]) ? arr[1][i] : max2;

	cout << max1 + max2;

	return 0;
}