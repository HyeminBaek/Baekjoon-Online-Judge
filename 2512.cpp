#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	long long low = 1, high = 0;
	long long* arr = new long long[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		high = max(high, arr[i]);
	}

	long long M; cin >> M;

	long long answer = 0;
	while (low <= high)
	{
		long long mid = (low + high) / 2;

		long long sum = 0;
		for (int i = 0; i < N; i++)
		{
			if (mid < arr[i])
				sum += mid;
			else
				sum += arr[i];
		}
		if (sum > M)
			high = mid - 1;

		else
		{
			low = mid + 1;
			answer = max(answer, mid);
		}
	}
	cout << answer;

	return 0;
}