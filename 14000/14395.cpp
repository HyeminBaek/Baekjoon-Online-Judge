#include <iostream>
#include <queue>
#include <string>
#include <set>
using namespace std;

string bfs(long long s, long long t)
{
	queue<pair<long long, string>> q;
	set<long long> visited;

	q.push({ s,"" }); visited.insert(s);
	while (!q.empty())
	{
		long long x = q.front().first;
		string answer = q.front().second; q.pop();
		if (x == t) return answer;

		for (int k = 0; k < 4; k++)
		{
			long long nx = 0; string c;
			if (k == 0)
			{
				nx = x * x; c = "*";
			}
			if (k == 1)
			{
				nx = x + x;   c = "+";
			}
			if (k == 2 && x >= 0)
			{
				nx = x - x; c = "-";
			}
			if (k == 3 && x != 0)
			{
				nx = x / x;   c = "/";
			}
			if (nx <= 1000000000 && visited.find(nx) == visited.end())
			{
				q.push({ nx,answer + c });
				visited.insert(nx);
			}
		}
	}
	return "-1";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	long long s, t;
	cin >> s >> t;
	if (s == t)
		cout << 0;
	else
		cout << bfs(s, t);

	return 0;
}