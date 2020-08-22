#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N; cin >> N;
	vector<pair<long long, long long>> v;
	for (int i = 0; i < N; i++)
	{
		int x, y; cin >> x >> y;
		v.push_back({ y,x });
	}
	sort(v.begin(), v.end());

	int answer = 1;
	long long next = v[0].first;
	for (int i = 1; i < N; i++)
	{
		if (v[i].second >= next)
		{
			answer++; next = v[i].first;
		}
	}
	cout << answer;

	return 0;
}