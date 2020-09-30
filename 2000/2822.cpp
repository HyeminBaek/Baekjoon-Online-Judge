#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	vector<pair<int, int>> v;
	for (int i = 1; i < 9; i++)
	{
		int score; cin >> score;
		v.push_back({ score,i });
	}
	sort(v.begin(), v.end());

	int sum = 0; vector<int> temp;
	for (int i = 7; i > 2; i--)
	{
		sum += v[i].first;
		temp.push_back(v[i].second);
	}
	sort(temp.begin(), temp.end());
	cout << sum << "\n";
	for (int i = 0; i < temp.size(); i++)
		cout << temp[i] << " ";

	return 0;
}