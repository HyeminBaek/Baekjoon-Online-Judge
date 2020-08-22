#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, L; cin >> N >> L;
	vector<int> leak;
	for (int i = 0; i < N; i++)
	{
		int x; cin >> x;
		leak.push_back(x);
	}

	sort(leak.begin(), leak.end());   reverse(leak.begin(), leak.end());

	int answer = 0;
	for (int i = 0; i < leak.size(); i++)
	{
		answer++;

		int temp = L - 1, up = 0;
		for (int j = i; j < leak.size() - 1; j++)
		{
			if (leak[j] - leak[j + 1] <= temp)
			{
				up++; temp -= leak[j] - leak[j + 1];
			}
			else   break;
		}
		i += up;
	}

	cout << answer;

	return 0;
}