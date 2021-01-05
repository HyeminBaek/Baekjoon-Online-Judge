#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;

	vector<pair<int, int>> v;

	for (int i = 0; i < N; i++)
	{
		int arr[5];
		for (int j = 0; j < 5; j++)
			cin >> arr[j];

		int mx = -1;

		for (int j = 0; j < 3; j++)
		{
			int sum = 0;
			for (int k = j + 1; k < 4; k++)
			{
				for (int l = k + 1; l < 5; l++)
				{
					sum = (arr[j] + arr[k] + arr[l]) % 10;
					mx = (sum > mx) ? sum : mx;
				}
			}
		}
		v.push_back({ mx ,i + 1 });
	}
	sort(v.begin(), v.end());

	cout << v.back().second;

	return 0;
}