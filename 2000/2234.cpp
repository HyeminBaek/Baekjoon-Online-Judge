#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct ewsn
{
	bool e, w, s, n;
};
int M, N;
ewsn arr[51][51];
int visited[51][51];

bool check(int x, int y)
{
	return (0 <= x && x < M && 0 <= y && y < N && visited[x][y] == -1);
}
int space(int i, int j)
{
	queue<pair<int, int>> q;
	q.push({ i,j }); visited[i][j] = 1;

	int dx[] = { 0,0,1,-1 }; //ewsn
	int dy[] = { 1,-1,0,0 };

	int c = 1;
	while (!q.empty())
	{
		int x = q.front().first, y = q.front().second;
		q.pop();

		if (!arr[x][y].e)
		{
			int nx = x + dx[0], ny = y + dy[0];
			if (check(nx, ny))
			{
				if (!arr[nx][ny].w)
				{
					visited[nx][ny] = ++c;
					q.push({ nx,ny });
				}
			}
		}
		if (!arr[x][y].w)
		{
			int nx = x + dx[1], ny = y + dy[1];
			if (check(nx, ny))
			{
				if (!arr[nx][ny].e)
				{
					visited[nx][ny] = ++c;
					q.push({ nx,ny });
				}
			}
		}
		if (!arr[x][y].s)
		{
			int nx = x + dx[2], ny = y + dy[2];
			if (check(nx, ny))
			{
				if (!arr[nx][ny].n)
				{
					visited[nx][ny] = ++c;
					q.push({ nx,ny });
				}
			}
		}
		if (!arr[x][y].n)
		{
			int nx = x + dx[3], ny = y + dy[3];
			if (check(nx, ny))
			{
				if (!arr[nx][ny].s)
				{
					visited[nx][ny] = ++c;
					q.push({ nx,ny });
				}
			}
		}
	}

	return c;
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int x; cin >> x;

			switch (x) //e4 w1 s8 n2 
			{
			case 0:
				arr[i][j] = { 0,0,0,0 }; break;
			case 1:
				arr[i][j] = { 0,1,0,0 }; break;
			case 2:
				arr[i][j] = { 0,0,0,1 }; break;
			case 3:
				arr[i][j] = { 0,1,0,1 }; break;
			case 4:
				arr[i][j] = { 1,0,0,0 }; break;
			case 5:
				arr[i][j] = { 1,1,0,0 }; break;
			case 6:
				arr[i][j] = { 1,0,0,1 }; break;
			case 7:
				arr[i][j] = { 1,1,0,1 }; break;
			case 8:
				arr[i][j] = { 0,0,1,0 }; break;
			case 9:
				arr[i][j] = { 0,1,1,0 }; break;
			case 10:
				arr[i][j] = { 0,0,1,1 }; break;
			case 11:
				arr[i][j] = { 0,1,1,1 }; break;
			case 12:
				arr[i][j] = { 1,0,1,0 }; break;
			case 13:
				arr[i][j] = { 1,1,1,0 }; break;
			case 14:
				arr[i][j] = { 1,0,1,1 }; break;
			case 15:
				arr[i][j] = { 1,1,1,1 }; break;
			}
		}
	}

	memset(visited, -1, sizeof(visited));
}
int main()
{
	init();

	int cnt = 0, max = 0;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visited[i][j] == -1)
			{
				cnt++;
				space(i, j);
			}
			max = (max < visited[i][j]) ? visited[i][j] : max;
		}
	}

	int rem = 0;
	
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			memset(visited, -1, sizeof(visited));

			if (arr[i][j].e)
			{
				if (j + 1 < N)
				{
					arr[i][j].e = 0;
					arr[i][j + 1].w = 0;
					int result = space(i, j);
					rem = (rem < result) ? result : rem;
					arr[i][j].e = 1;
					arr[i][j + 1].w = 1;
				}
			}
			if (arr[i][j].w)
			{
				if (j - 1 >= 0)
				{
					arr[i][j].w = 0;
					arr[i][j - 1].e = 0;
					int result = space(i, j);
					rem = (rem < result) ? result : rem;
					arr[i][j].w = 1;
					arr[i][j - 1].e = 1;
				}
			}
			if (arr[i][j].s)
			{
				if (i + 1 < M)
				{
					arr[i][j].s = 0;
					arr[i+1][j].n = 0;
					int result = space(i, j);
					rem = (rem < result) ? result : rem;
					arr[i][j].s = 1;
					arr[i + 1][j].n = 1;
				}
			}
			if (arr[i][j].n)
			{
				if (i - 1 >= 0)
				{
					arr[i][j].n = 0;
					arr[i - 1][j].s = 0;
					int result = space(i, j);
					rem = (rem < result) ? result : rem;
					arr[i][j].n = 1;
					arr[i - 1][j].s = 1;
				}
			}
		}
	}

	cout << cnt << "\n" << max << "\n" << rem;

	return 0;
}