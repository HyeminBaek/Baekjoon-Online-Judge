#include <iostream>
#include <queue>
using namespace std;

int tomato[1000][1000];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 }; 
int m, n, sx, sy, ex, ey;
queue<pair<int,int>> q;

void bfs()
{
	while(!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (0 <= nx && nx < n && 0 <= ny && ny < m)
			{
				if (tomato[nx][ny] == 0)
				{
					tomato[nx][ny] = tomato[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
			//배열벗어나지마, -1,1 만나면 pass, check 배열 false 이고 0
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> m >> n;

	bool tf = false;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> tomato[i][j];

			if (tomato[i][j] == 1)
				q.push(make_pair(i, j));
			else if (tomato[i][j] == 0)
				tf = true;
		}
	}
	if (tf)
	{
		bfs();

		int max = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (tomato[i][j] == 0)
				{
					cout << -1;
					exit(0);
				}
				else
				{
					if (tomato[i][j] > max)
						max = tomato[i][j];
				}
			}
		}
		cout << max - 1;
	}
	else
		cout << 0;

	return 0;
}