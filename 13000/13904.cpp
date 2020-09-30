#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	vector<pair<int,int>> v;
	for (int i = 0; i < N; i++)
	{
		int x, y; cin >> x >> y;
		v.push_back({ x,y });
	}
	sort(v.begin(), v.end());

	int answer = 0;
	for (int k = N; k > 0; k--)
	{
		int maxS = -1, maxIndex = -1;
		for (int i = v.size() - 1; i >= 0; i--)
		{
			if (k > v[i].first) break;
			else
			{
				if (v[i].second > maxS)
				{
					maxS = v[i].second;
					maxIndex = i;
				}
			}
		}
		if (maxS != -1 && maxIndex != -1)
		{
			answer += maxS;
			v.erase(v.begin() + maxIndex);
		}
	}
	cout << answer;

	return 0;
}