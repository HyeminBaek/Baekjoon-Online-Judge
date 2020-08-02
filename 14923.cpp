#include <iostream>
#include <queue>
using namespace std;

int N, M, Ex, Ey;
bool visited[1001][1001][2];
int map[1001][1001];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int bfs(int i, int j)
{
	queue<pair<pair<int, int>, pair<int, int>>> q; // (x,y) 좌표, 벽뚫기 여부,거리 기록
	q.push(make_pair(make_pair(i, j), make_pair(0, 0)));

	while (!q.empty())
	{
		int x = q.front().first.first; int y = q.front().first.second;
		int flag = q.front().second.first; int num = q.front().second.second;
		q.pop();

		if (x == Ex - 1 && y == Ey - 1) //종료 조건
			return num;

		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k]; int ny = y + dy[k];
			if (0 <= nx && nx < N && 0 <= ny && ny < M)
			{
				//갈 수 있는데 안간 곳
				if (map[nx][ny] == 0 && visited[nx][ny][flag] == false)
				{
					visited[nx][ny][flag] = true;
					q.push(make_pair(make_pair(nx, ny), make_pair(flag, num + 1)));
				}
				//벽인데 안간 곳
				if (map[nx][ny] == 1 && !visited[nx][ny][flag + 1] && flag == 0)
				{
					visited[nx][ny][flag + 1] = true;
					q.push(make_pair(make_pair(nx, ny), make_pair(1, num + 1)));
				}
			}
		}
	}
	return -1;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int Hx, Hy;
	cin >> N >> M >> Hx >> Hy >> Ex >> Ey;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
	}
	visited[Hx - 1][Hy - 1][0] = true;

	cout << bfs(Hx - 1, Hy - 1);

	return 0;
}