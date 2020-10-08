#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int K, N; cin >> K >> N;

	long long low = 1, high = 0;
	long long arr[10000];
	for (int i = 0; i < K; i++)
	{
		cin >> arr[i];
		high = (high < arr[i]) ? arr[i] : high;
	}
	long long answer = 0;
	while (low <= high)
	{
		long long mid = (low + high) / 2;

		int sum = 0;
		for (int i = 0; i < K; i++)
		{
			sum += arr[i] / mid;
		}
		//cout << sum << " " << low << " " << mid << " " << high << endl;
		if (sum >= N)
		{
			low = mid + 1;
			answer = (answer < mid) ? mid : answer;
		}
		else
		{
			high = mid - 1;
		}
	}
	cout << answer;

	return 0;
}