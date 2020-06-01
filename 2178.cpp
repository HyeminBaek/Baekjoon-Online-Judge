#include <iostream>
#include <string>
#include <queue>
using namespace std;

int n, m;
queue<pair<int, int>> q;
int arr[101][101];
int d[101][101] = { 0, };
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void bfs()
{
	q.push(make_pair(1, 1));
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		//cout << x << " " << y << endl;

		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (0 < nx && nx <= n && 0 < ny && ny <= m)
			{
				if (arr[nx][ny] == 1 && d[nx][ny] == 0)
				{
					d[nx][ny] = d[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		for (int j = 1; j <= m; j++)
			arr[i][j] = s.at(j - 1) - '0';
	}

	bfs();

	cout << d[n][m] + 1;

	return 0;
}