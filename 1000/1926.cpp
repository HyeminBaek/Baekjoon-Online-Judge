#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M, temp;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int map[500][500];
bool visited[500][500];

void dfs(int x, int y)
{
	visited[x][y] = true;
	temp++;
	for (int k = 0; k < 4; k++)
	{
		int nx = x + dx[k]; int ny = y + dy[k];
		if (0 <= nx && nx < N && 0 <= ny && ny < M)
		{
			if (!visited[nx][ny] && map[nx][ny] == 1)
			{
				dfs(nx, ny);
			}
		}
	}
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
	}
}
int main()
{
	init();

	int num = 0, answer = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (!visited[i][j]&& map[i][j] == 1)
			{
				num++; dfs(i, j);
				answer = max(answer, temp);
				temp = 0;
			}
		}
	}

	cout << num << "\n" << answer;

	return 0;
}