#include <iostream>
using namespace std;

int main()
{
	int T; cin >> T;
	for (T; T > 0; T--)
	{
		int arr[5];
		for (int i = 0; i < 5; i++)
			cin >> arr[i];

		int max = arr[0], min = arr[0], maxidx = 0, minidx = 0;
		for (int i = 1; i < 5; i++)
		{
			if (max < arr[i])
			{
				max = arr[i]; maxidx = i;
			}
			if (min > arr[i])
			{
				min = arr[i]; minidx = i;
			}
		}

		int answer[3]; int idx = 0;
		for (int i = 0; i < 5; i++)
		{
			if (i == maxidx || i == minidx) continue;
			answer[idx++] = arr[i];
		}
		int sum = 0;  min = answer[0], max = answer[0];
		for (int i = 0; i < 3; i++)
		{
			max = (max > answer[i]) ? max : answer[i];
			min = (min > answer[i]) ? answer[i] : min;
			sum += answer[i];
		}
		if (max - min >= 4)
			cout << "KIN\n";
		else
			cout << sum << endl;
	}
	return 0;
}