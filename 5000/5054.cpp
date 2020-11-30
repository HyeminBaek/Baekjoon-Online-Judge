#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;
	for (int i = 0; i < T; i++)
	{
		int n; cin >> n;
		vector<int> v;
		for (int j = 0; j < n; j++)
		{
			int x; cin >> x;
			v.push_back(x);
		}

		sort(v.begin(), v.end());
		int sum = 0;
		for (int j = 0; j < v.size() - 1; j++)
			sum += (v[j + 1] - v[j]) * 2;
		
		cout << sum << "\n";
	}

	return 0;
}