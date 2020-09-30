#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int arr[50][50];
int visited[50][50];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int earthworm, m, n, k;

void bfs(int i,int j)
{
	queue<pair<int, int>> q;
	q.push(make_pair(i, j));

	visited[i][j] = 0;
	while (!q.empty())
	{
		int x = q.front().first; int y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (0 <= nx && nx < m && 0 <= ny && ny < n)
			{
				if (arr[nx][ny] == 1 && visited[nx][ny] == -1)
				{
					visited[nx][ny] = 0; arr[nx][ny] = 0;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	earthworm++;
}

int main()
{
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		memset(arr, 0, sizeof(arr));
		memset(visited, -1, sizeof(visited));

		cin >> m >> n >> k;

		for (int j = 0; j < k; j++) //배추 입력
		{
			int x; int y;
			cin >> x >> y;

			arr[x][y] = 1;
		}

		earthworm = 0;
		for (int a = 0; a < m; a++)
		{
			for (int b = 0; b < n; b++)
			{
				if(arr[a][b]==1)
					bfs(a,b);
			}
		}

		cout << earthworm << "\n";
	}

	return 0;
}