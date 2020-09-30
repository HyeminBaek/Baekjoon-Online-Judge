#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N, sum;
vector<int> g[100];
vector<int> t[100];
bool visited[100];

void dfs(int x, vector<int> v[])
{
	//cout << x << " " << sum << endl;
	if (sum >= (N + 1) / 2) return;

	for (int i = 0; i < v[x].size(); i++)
	{
		if (!visited[v[x][i]])
		{
			visited[v[x][i]] = true;
			sum++;   dfs(v[x][i], v);
		}
	}
}
void init()
{
	int M; cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int x, y; cin >> x >> y;
		t[x].push_back(y);    g[y].push_back(x);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int answer = 0;
	init();

	for (int i = 1; i <= N; i++)
	{
		memset(visited, false, sizeof(visited)); sum = 0; visited[i] = true;
		dfs(i, g);
		if (sum >= (N + 1) / 2)   answer++;
		memset(visited, false, sizeof(visited)); sum = 0; visited[i] = true;
		dfs(i, t);
		if (sum >= (N + 1) / 2)   answer++;
	}

	cout << answer;

	return 0;
}