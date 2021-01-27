#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	
	vector<long long> v;
	for (int i = 0; i < N; i++)
	{
		long long x; cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());

	long long answer = abs(v[0] + v[1] + v[v.size()-1]);
	long long l = 0, m = 1, h = v.size() - 1;

	for(int mid = 1;mid<v.size()-1;mid++)
	{ 
		long long low = 0, high = v.size() - 1;
		while (l < h)
		{
			if (mid <= low ||mid>=high|| abs(high - low) == 1)
				break;

			if (answer > abs(v[low] + v[mid] + v[high]))
			{
				answer = abs(v[low] + v[mid] + v[high]);
				l = low, m = mid, h = high;
			}
			if (v[low] + v[mid] + v[high] > 0)
				high--;
			else if (v[low] + v[mid] + v[high] == 0)
			{
				l = low, m = mid, h = high;
				break;
			}
			else low++;
		}
	}

	cout << v[l] << " " << v[m] << " " << v[h];

	return 0;
}