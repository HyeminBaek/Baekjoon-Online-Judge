#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	vector<pair<int, pair<int, string>>> boj;
	for (int i = 0; i < n; i++)
	{
		int age;
		string name;
		cin >> age >> name;
		boj.push_back(make_pair(age, make_pair(i, name)));
	}
	sort(boj.begin(), boj.end());

	for (int i = 0; i < n; i++)
		cout << boj[i].first << " " << boj[i].second.second << "\n";

	return 0;
}