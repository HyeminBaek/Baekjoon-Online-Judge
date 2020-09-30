#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M, low, high = 0; cin >> N >> M;
	int* arr = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		low = min(low, arr[i]);
		high += arr[i];
	}

	int answer = 0;
	while (low <= high)
	{
		int mid = (low + high) / 2;

		int C = 1, temp = mid; bool flag = false;
		for (int i = 0; i < N; i++)
		{
			if (mid < arr[i])
			{
				flag = true; break;
			}
			if (temp >= arr[i])
			{
				temp -= arr[i];
			}
			else
			{
				C++; temp = mid;
				temp -= arr[i];
			}
		}
		if (!flag&& C <= M)
		{
			answer = mid; high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}

	cout << answer;

	return 0;
}