#include <iostream>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

int R, C;
char map[51][51];
int water[51][51];
int visited[51][51];

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

queue<pair<int, int>> q;
queue<pair<int, int>> w;

void bfs()
{
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k]; int ny = y + dy[k];
			if (0 <= nx && nx < R && 0 <= ny && ny < C)
			{
				if (map[nx][ny] == '.' || map[nx][ny] == 'D')
				{
					if (map[nx][ny] == 'D')
					{
						cout << visited[x][y] + 1; return;
					}
					if (visited[nx][ny] == -1 && (water[nx][ny] == -1 || water[nx][ny] > visited[x][y] + 1))
					{
						visited[nx][ny] = visited[x][y] + 1;
						q.push(make_pair(nx, ny));
					}
				}
			}
		}
	}
	cout << "KAKTUS";
}
void waterInit()
{
	while (!w.empty())
	{
		int x = w.front().first; int y = w.front().second;
		w.pop();

		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k]; int ny = y + dy[k];
			if (0 <= nx && nx < R && 0 <= ny && ny < C)
			{
				if (map[nx][ny] == '.'&&water[nx][ny] == -1)
				{
					water[nx][ny] = water[x][y] + 1;
					w.push(make_pair(nx, ny));
				}
			}
		}
	}
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	memset(visited, -1, sizeof(visited));
	memset(water, -1, sizeof(water));

	cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> map[i][j];

			if (map[i][j] == 'S')
			{
				q.push(make_pair(i, j));
				map[i][j] = '.'; visited[i][j] = 0;
			}
			else if (map[i][j] == '*')
			{
				w.push(make_pair(i, j)); water[i][j] = 0;
			}
		}
	}
}
int main()
{
	init();
	waterInit();
	bfs();

	return 0;
}