#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	priority_queue<int,vector<int>,greater<int>> q;

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;

		switch (x)
		{
		case 0:
			if (q.empty())
				cout << 0 << "\n";
			else
			{
				cout << q.top() << "\n";
				q.pop();
			}
			break;

		default:
			q.push(x);
		}
	}

	return 0;
}