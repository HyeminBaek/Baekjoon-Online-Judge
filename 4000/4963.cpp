#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int w, h, answer;
int map[51][51];
int visited[51][51];

int dx[] = { -1,1,0,0,1,-1,1,-1 };
int dy[] = { 0,0,1,-1,1,1,-1,-1 };

void bfs(int i, int j)
{
	queue<pair<int, int>> q;
	q.push(make_pair(i, j));

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int k = 0; k < 8; k++)
		{
			int nx = x + dx[k]; int ny = y + dy[k];

			if (0 <= nx && nx < h && 0 <= ny && ny < w)
			{
				if (visited[nx][ny] == -1 && map[nx][ny] == 1)
				{
					visited[nx][ny] = 0;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	answer++;
}
void init(int w, int h)
{
	memset(visited, -1, sizeof(visited));

	answer = 0;

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
			cin >> map[i][j];
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (cin >> w >> h)
	{
		if (w == 0 && h == 0) break;
		init(w, h);

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (visited[i][j] == -1 && map[i][j] == 1)
				{
					bfs(i, j); //cout << i << " " << j << endl;
				}

			}
		}
		cout << answer << "\n";
	}

	return 0;
}