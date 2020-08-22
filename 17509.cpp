#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<pair<int, int>> v;
	for (int i = 0; i < 11; i++)
	{
		int x, y; cin >> x >> y;
		v.push_back({ x,y });
	}

	sort(v.begin(), v.end());

	int time = 0, answer = 0;
	for (int i = 0; i < 11; i++)
	{

		time += v[i].first;
		answer += v[i].second * 20 + time;
	}
	cout << answer;

	return 0;
}