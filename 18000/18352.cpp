#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, K, X;
int visited[300001];
vector<int> v[300001];

void sum()
{
	bool flag = false;
	for (int i = 1; i <= N; i++)
	{
		if (visited[i] == K)
		{
			flag = true; cout << i << "\n";
		}
	}

	if (!flag) cout<< -1;
}
void bfs(int i)
{
	queue<int> q; q.push(i);

	while (!q.empty())
	{
		int x = q.front(); q.pop();

		for (int k = 0; k < v[x].size(); k++)
		{
			int nx = v[x][k];

			if (visited[nx] > visited[x] + 1)
			{
				visited[nx] = visited[x] + 1;
				q.push(nx);
			}
		}
	}
	
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int M; cin >> N >> M >> K >> X;
	for (M; M > 0; M--)
	{
		int x, y; cin >> x >> y;
		v[x].push_back(y);
	}
	for (int i = 1; i <= N; i++)
		visited[i] = 987654321;

	visited[X] = 0;
}
int main()
{
	init();
	bfs(X);
	sum();

	return 0;
}