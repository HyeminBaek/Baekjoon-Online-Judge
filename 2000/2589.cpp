#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int W, L, answer;
char map[51][51];
int visited[51][51];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
queue<pair<int, int>> land;

void bfs(int i, int j)
{
	queue<pair<int, int>> q;
	q.push({ i,j }); visited[i][j] = 0;

	while (!q.empty())
	{
		int x = q.front().first; int y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k]; int ny = y + dy[k];

			if (0 <= nx && nx < W && 0 <= ny && ny < L)
			{
				if (map[nx][ny] == 'L'&&visited[nx][ny] == -1)
				{
					visited[nx][ny] = visited[x][y] + 1;
					q.push({ nx,ny });
				}
			}
		}
	}
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> W >> L;
	for (int i = 0; i < W; i++)
	{
		for (int j = 0; j < L; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'L')
				land.push({ i,j });
		}
	}
}
int main()
{
	init();
	while (!land.empty())
	{
		memset(visited, -1, sizeof(visited));
		bfs(land.front().first, land.front().second);
		land.pop();

		for (int i = 0; i < W; i++)
		{
			for (int j = 0; j < L; j++)
			{
				if (visited[i][j] == -1) continue;
				answer = max(answer, visited[i][j]);
			}
		}
	}

	cout << answer;

	return 0;
}