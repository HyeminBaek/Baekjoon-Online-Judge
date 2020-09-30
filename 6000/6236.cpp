#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M, low = 10000, high = 0;   cin >> N >> M;
	vector<int> v;
	for (int i = 0; i < N; i++)
	{
		int x; cin >> x;
		v.push_back(x);
		low = min(low, v[i]);
		high += v[i];
	}

	int answer = high;

	while (low <= high)
	{
		int mid = (low + high) / 2;
		//cout << low << " " << mid << " " << high << endl;

		int C = 1, left = mid; bool flg = false;
		for (int i = 0; i < N; i++)
		{
			if (mid < v[i])
			{
				flg = true; break;
			}
			if (left >= v[i])
				left -= v[i];
			else
			{
				C++;
				left = mid;
				left -= v[i];
			}
		}

		if (!flg&&C <= M)
		{
			answer = mid;
			high = mid - 1;
		}
		else
			low = mid + 1;
	}

	cout << answer;

	return 0;
}