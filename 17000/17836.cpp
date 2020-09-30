#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int N, M, T;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };
bool visited[101][101][2];
int map[101][101];

int bfs()
{
	queue<pair<pair<int, int>, pair<int, int>>> q; //(x,y),(검 얻음여부,time)
	q.push({ { 1,1 }, { 0,0 } });

	while (!q.empty())
	{
		int x = q.front().first.first; int y = q.front().first.second;
		int tf = q.front().second.first; int num = q.front().second.second;
		q.pop();

		if (x == N && y == M)   return num;
		if (num > T) return -1;
		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k]; int ny = y + dy[k];
			if (0 < nx && nx <= N && 0 < ny && ny <= M)
			{
				if (tf == 1 && map[nx][ny] == 1 && !visited[nx][ny][tf])
				{
					visited[nx][ny][tf] = true;
					q.push({ {nx,ny},{tf,num + 1} });
				}
				if (map[nx][ny] == 2 && !visited[nx][ny][tf])
				{
					visited[nx][ny][tf] = true;
					q.push({ {nx,ny},{tf + 1,num + 1} });
				}
				if (map[nx][ny] == 0 && !visited[nx][ny][tf])
				{
					visited[nx][ny][tf] = true;
					q.push({ {nx,ny},{tf,num + 1} });
				}
			}
		}
	}
	return -1;
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> T;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
			cin >> map[i][j];
	}
	memset(visited, false, sizeof(visited));
}
int main()
{
	init();
	int temp = bfs();
	if (temp > 0) cout << temp;
	else cout << "Fail";

	return 0;
}