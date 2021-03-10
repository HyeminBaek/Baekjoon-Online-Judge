#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N;
int map[125][125];
int visited[125][125];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

void bfs()
{
	queue<pair<int, int>> q;
	q.push({ 0,0 }); visited[0][0] = map[0][0];
	
	while (!q.empty())
	{
		int x = q.front().first, y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k], ny = y + dy[k];

			if (0 <= nx && nx < N && 0 <= ny && ny < N)
			{
				if (visited[nx][ny] > visited[x][y] + map[nx][ny])
				{
					visited[nx][ny] = visited[x][y] + map[nx][ny];
					q.push({ nx,ny });
				}
			}
		}
	}
}
void init()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			visited[i][j] = 987654321;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int idx = 0;
	while (cin>>N)
	{
		if (N == 0) break;
		init();
		bfs();

		cout << "Problem " << ++idx << ": " << visited[N - 1][N - 1] << "\n";
	}
	return 0;
}