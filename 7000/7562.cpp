#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int l, a, b, mx, my;
bool visited[301][301];
int dx[] = { -1,-2,-1,-2,1,2,1,2 };
int dy[] = { 2,1,-2,-1,-2,-1,2,1 };

int bfs()
{
	queue<pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(a, b), 0));
	visited[a][b] = true;

	while (!q.empty())
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		int num = q.front().second;
		q.pop();

		if (x == mx && y == my) return num;

		for (int k = 0; k < 8; k++)
		{
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (0 <= nx && nx < l && 0 <= ny && ny < l)
			{
				if (visited[nx][ny] == false)
				{
					visited[nx][ny] = true;
					q.push(make_pair(make_pair(nx, ny), num + 1));
				}
			}
		}
	}
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	memset(visited, false, sizeof(visited));
	cin >> l >> a >> b >> mx >> my;
}
int main()
{
	int t; cin >> t;

	for (int i = 0; i < t; i++)
	{
		init();
		cout << bfs() << endl;
	}

	return 0;
}