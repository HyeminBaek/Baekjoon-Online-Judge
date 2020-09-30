#include <iostream>
#include <vector>
using namespace std;

int N, M, answer;
bool visited[1001];
vector<int> v[1001];

void dfs(int x)
{
	visited[x] = 1;

	for (int i = 0; i < v[x].size(); i++)
	{
		if (visited[v[x][i]] == 0)
			dfs(v[x][i]);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int x, y;
		cin >> x >> y;

		v[x].push_back(y); v[y].push_back(x);
	}
	for (int i = 1; i <= N; i++)
	{
		if (visited[i] == 0)
		{
			dfs(i); answer++;
		}
	}

	cout << answer;

	return 0;
}