#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N; cin >> N;

	vector<pair<long long, string>> v;
	for (int i = 0; i < N; i++)
	{
		string s; long long n;
		cin >> s >> n;

		v.push_back({ n,s });
	}
	sort(v.begin(), v.end());

	int idx = v.size() - 1;
	for (int i = v.size() - 2; i >= 0; i--)
	{
		if (v[i].first == v.back().first)
			idx = i;
		else break;
	}

	cout << v[idx].second;

	return 0;
}