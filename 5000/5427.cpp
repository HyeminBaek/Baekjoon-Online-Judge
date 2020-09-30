5427
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int R, C;
char map[1001][1001];
int fire[1001][1001];
int visited[1001][1001];

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,-1,1 };

queue<pair<int, int>> q;
queue<pair<int, int>> f;

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
			if (0 <= nx && nx < C && 0 <= ny && ny < R)
			{
				if (map[nx][ny] == '.')
				{
					if (visited[nx][ny] == -1 && (fire[nx][ny] == -1 || fire[nx][ny] > visited[x][y] + 1))
					{
						visited[nx][ny] = visited[x][y] + 1;
						q.push(make_pair(nx, ny));
					}
				}
			}
			else
			{
				cout << visited[x][y] + 1 << endl; return;
			}
		}
	}
	cout << "IMPOSSIBLE" << endl;
}
void fireInit()
{
	while (!f.empty())
	{
		int x = f.front().first; int y = f.front().second;
		f.pop();

		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k]; int ny = y + dy[k];
			if (0 <= nx && nx < C && 0 <= ny && ny < R)
			{
				if (map[nx][ny] == '.'&&fire[nx][ny] == -1)
				{
					fire[nx][ny] = fire[x][y] + 1;
					f.push(make_pair(nx, ny));
				}
			}
		}
	}
}
void init()
{
	memset(visited, -1, sizeof(visited));
	memset(fire, -1, sizeof(fire));

	while (!q.empty())
		q.pop();
	while (!f.empty())
		f.pop();

	cin >> R >> C;
	for (int i = 0; i < C; i++)
	{
		for (int j = 0; j < R; j++)
		{
			cin >> map[i][j];

			if (map[i][j] == '@')
			{
				q.push(make_pair(i, j));
				map[i][j] = '.'; visited[i][j] = 0;
			}
			else if (map[i][j] == '*')
			{
				f.push(make_pair(i, j)); fire[i][j] = 0;
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;

	for (int i = 0; i < T; i++)
	{
		init();
		fireInit();
		bfs();
	}

	return 0;
}