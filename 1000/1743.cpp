#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M;
bool map[101][101];
bool visited[101][101];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };

int bfs(int i, int j)
{
	queue<pair<int, int>> q;
	memset(visited, false, sizeof(visited));
	q.push({ i,j }); visited[i][j] = true;

	int r = 1;
	while (!q.empty())
	{
		int x = q.front().first; int y = q.front().second; q.pop();

		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k]; int ny = y + dy[k];
			if (0 < nx <= N && 0 < ny <= M)
			{
				if (map[nx][ny] && !visited[nx][ny])
				{
					visited[nx][ny] = true;
					q.push({ nx,ny });
					r++;
				}
			}
		}
	}
	return r;
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int K;
	cin >> N >> M >> K;
	for (int i = 0; i < K; i++)
	{
		int x, y; cin >> x >> y;
		map[x][y] = true;
	}
}
int main()
{
	init();

	int answer = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (map[i][j])
				answer = max(answer, bfs(i, j));
		}
	}
	cout << answer;

	return 0;
}
