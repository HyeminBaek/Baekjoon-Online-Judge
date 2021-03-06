#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int N, answer;
vector<pair<int, int>> v[100001];
bool visited[100001];

void dfs(int nxt,int sum)
{
	visited[nxt] = true;
	answer = max(answer, sum);

	for (int k = 0; k < v[nxt].size(); k++)
	{
		if (!visited[v[nxt][k].first])
		{
			dfs(v[nxt][k].first, sum + v[nxt][k].second);
		}
	}
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int V; cin >> V;
		
		int x, y;
		while (cin >> x)
		{
			if (x == -1) break;
			else
			{
				cin >> y;
				v[V].push_back({ x,y });
			}
		}
	}
}
int main()
{
	init();
	for (int i = 1; i <= N; i++)
	{
		memset(visited, false, sizeof(visited));
		dfs(i, 0);
	}
	
	cout << answer;

	return 0;
}