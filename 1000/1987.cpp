#include <iostream>
#include <algorithm>
using namespace std;

int R, C, answer;
bool ABC[26];
bool visited[21][21];
char map[21][21];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

void dfs(int x, int y, int cnt)
{
	answer = max(answer, cnt);
	for (int k = 0; k < 4; k++)
	{
		int nx = x + dx[k]; int ny = y + dy[k];

		if (0 < nx&&nx <= R && 0 < ny&&ny <= C)
		{
			if (!visited[nx][ny] && !ABC[map[nx][ny] - 'A'])
			{
				visited[nx][ny] = true;
				ABC[map[nx][ny] - 'A'] = true;
				dfs(nx, ny, cnt + 1);
				visited[nx][ny] = false;
				ABC[map[nx][ny] - 'A'] = false;
			}
		}
	}
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> R >> C;
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
			cin >> map[i][j];
	}
	visited[1][1] = true; ABC[map[1][1] - 'A'] = true;
}
int main()
{
	init();
	dfs(1, 1, 1);
	cout << answer;

	return 0;
}