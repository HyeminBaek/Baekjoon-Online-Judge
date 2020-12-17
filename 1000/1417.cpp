#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	
	vector<int> v;
	for (int i = 1; i <= N; i++)
	{
		int num; cin >> num;
		v.push_back(num);
	}

	int init = v.front();
	while (1)
	{
		int max = -1, maxIndex = -1;

		for (int i = 0; i < N; i++)
		{
			if (max < v[i])
			{
				max = v[i]; maxIndex = i;
			}
		}

		if (maxIndex == 0)
		{
			bool flag = false;
			for (int i = 1; i < N; i++)
			{
				if (v[i] == max)
				{
					flag = true; break;
				}
			}
			if (!flag)
			{
				cout << v[maxIndex] - init;
				return 0;
			}
			else
			{
				cout << v[maxIndex] + 1 - init;
				return 0;
			}
		}

		v[maxIndex]--;
		v[0]++;
	}

	return 0;
}