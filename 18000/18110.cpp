#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;
	if (n == 0)
	{
		cout << 0; return 0;
	}
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		int x; cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	int avg = round(n * 0.15);
	int sum = 0, num = 0;
	for (int i = avg; i < v.size() - avg; i++)
	{
		sum += v[i]; num++;
	}
	int answer = (int)(round((double)sum / (double)(num)));
	cout << answer;

	return 0;
}