#include <iostream>
#include <string>
#include <queue>
using namespace std;

int wall[1001][1001];
int d[1001][1001][2];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int n, m;
queue<pair<pair<int, int>,int>> q;

void bfs(int& distance)
{
	q.push(make_pair(make_pair(1, 1), 0));
	d[1][1][0] = 1;

	while (!q.empty())
	{
		//cout << q.front().first<<" "<<q.front().second.first;

		int x = q.front().first.first;
		int y = q.front().first.second;
		int tf = q.front().second;
		q.pop();

		//cout << x << " " << y << endl;

		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (0 < nx && nx <= n && 0 < ny && ny <= m)
			{
				//이동 O,방문X
				if (wall[nx][ny] == 0 && d[nx][ny][tf] == 0)
				{
					d[nx][ny][tf] = d[x][y][tf] + 1;
					q.push(make_pair(make_pair(nx, ny), tf));
				}
				//벽,방문X
				if (wall[nx][ny] == 1 && tf == 0 && d[nx][ny][tf + 1] == 0)
				{
					d[nx][ny][tf + 1] = d[x][y][tf] + 1;
					q.push(make_pair(make_pair(nx, ny), 1));
				}
			}
		}
	}
	//cout << d[6][4][0] <<" "<<d[6][4][1]<< endl;
	if (d[n][m][0] == 0 && d[n][m][1] == 0)
		distance = -1;
	else if(d[n][m][0]!=0&&d[n][m][1]!=0)
		distance = (d[n][m][0] > d[n][m][1]) ? d[n][m][1] : d[n][m][0];
	else if (d[n][m][0] == 0)
		distance = d[n][m][1];
	else if(d[n][m][1]==0)
		distance = d[n][m][0];
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
			wall[i][j] = s[j - 1] - '0';
	}

	int distance = -1;
	bfs(distance);

	cout << distance;

	return 0;
}