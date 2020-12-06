#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int com;
bool visited[10001];
vector<int> answer;

void bfs(int x,vector<pair<int,int>> v[10001])
{
	//시간 짧은 순서로 배열해야 함
	priority_queue <pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> q;
	q.push({ 0,x });
	while (!q.empty())
	{
		int node = q.top().second, time = q.top().first;
		q.pop();

		if (!visited[node])
		{
			visited[node] = true;
			com++;
			answer.push_back(time);

			for (int i = 0; i < v[node].size(); i++)
			{
				int nx = v[node][i].second;
				if (!visited[nx])
				{
					int ny = time+v[node][i].first;
					q.push({ ny,nx });
				}
			}
		}
	}
}
void init()
{
	memset(visited, false, sizeof(visited));
	answer.clear();
	com = 0;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t; cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n, d, c; cin >> n >> d >> c;
		init();

		vector<pair<int, int>> v[10001];
		for (int i = 0; i < d; i++)
		{
			int a, b, s; cin >> a >> b >> s;
			v[b].push_back({ s,a });
		}
		bfs(c,v);

		sort(answer.begin(), answer.end());
		cout << com << " " << answer.back() << "\n";
	}

	return 0;
}