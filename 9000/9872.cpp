#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	vector<pair<int,string>> v;
	for (int i = 0; i < N; i++)
	{
		vector<string> temp;
		string a, b, c; cin >> a >> b >> c;

		temp.push_back(a); temp.push_back(b); temp.push_back(c);
		sort(temp.begin(), temp.end());

		string push = temp[0] + " " + temp[1] + " " + temp[2];

		bool flag = false; int idx = -1;
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i].second == push)
			{
				flag = true; idx = i;  break;
			}
		}
		if (!flag)
			v.push_back({ 1,push });
		else
			v[idx].first++;
	}

	sort(v.begin(), v.end());
	cout << v.back().first;

	return 0;
}