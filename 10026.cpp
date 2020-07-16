#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

int N, answer;
bool tf = false;//적록색약 on/off
char arr[101][101];
bool visited[101][101];

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };


void bfs(int i,int j)
{
	queue<pair<int, int>> q;
	q.push(make_pair(i, j));

	while (!q.empty())
	{
		int x = q.front().first; int y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k]; int ny = y + dy[k];
			if (0 <= nx && nx < N && 0 <= ny && ny < N)
			{
				if (!tf)
				{
					if (arr[nx][ny] == arr[x][y] && visited[nx][ny] == 0)
					{
						visited[nx][ny] = 1;
						q.push(make_pair(nx, ny));
					}
				}
				else
				{
					if (visited[nx][ny] == 0)
					{
						if(arr[x][y]=='R'||arr[x][y]=='G')
						{
							if (arr[nx][ny] == 'R' || arr[nx][ny] == 'G')
							{
								visited[nx][ny] = 1;
								q.push(make_pair(nx, ny));
							}
						}
						else
						{
							if (arr[nx][ny] == arr[x][y])
							{
								visited[nx][ny] = 1;
								q.push(make_pair(nx, ny));
							}
						}
					}
				}
			}
		}
	}
	answer++;
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			char c;
			cin >> c;
			arr[i][j] = c;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visited[i][j] == 0)
			{
				bfs(i, j);
			}
		}
	}
	cout << answer << " ";

	answer = 0;
	memset(visited, 0, sizeof(visited));
	tf = true;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visited[i][j] == 0)
			{
				bfs(i, j);
			}
		}
	}
	cout << answer;

	return 0;
}