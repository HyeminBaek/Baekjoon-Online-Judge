#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int k, w, h;

int knightx[] = { -1,-2,1,2,-1,-2,1,2 };
int knighty[] = { 2,1,2,1,-2,-1,-2,-1 };
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };

int visited[201][201][31];
int map[201][201];

queue<pair<pair<int, int>,pair<int,int>>> q; //x,y,k,���� Ƚ��

/*
TEST CASE 1
INPUT:
3
4 5
0 1 1 1
1 1 0 1
1 1 1 1
1 1 1 0
1 1 1 0
OUTPUT: 3
*/
int bfs()
{
	q.push(make_pair(make_pair(1, 1), make_pair(0, 0)));
	visited[1][1][0] = 0;
	while (!q.empty())
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		int next_k = q.front().second.first;
		int num = q.front().second.second;

		q.pop();

		if (x == h && y == w) // ��������
			return num;

		if (next_k < k)
		{
			for (int a = 0; a < 8; a++)
			{
				int nx = x + knightx[a];
				int ny = y + knighty[a];

				if (0 < nx&&nx <= h && 0 < ny&&ny <= w)
				{
					if (map[nx][ny] == 0 && visited[nx][ny][next_k + 1] == -1)
					{
						visited[nx][ny][next_k + 1] = visited[x][y][next_k] + 1;
						q.push(make_pair(make_pair(nx, ny), make_pair(next_k + 1, num + 1)));
					}
				}
			}
		}
		//��ó�� �̵������� ���� ������ó�� �̵��� �����ϹǷ� else������ ���� �ʴ´�
		for (int a = 0; a < 4; a++)
		{
			int nx = x + dx[a];
			int ny = y + dy[a];

			if (0 < nx&&nx <= h && 0 < ny&&ny <= w)
			{
				if (map[nx][ny] == 0 && visited[nx][ny][next_k] == -1)
				{
					visited[nx][ny][next_k] = visited[x][y][next_k] + 1;
					q.push(make_pair(make_pair(nx, ny), make_pair(next_k, num + 1)));
				}
			}
		}

	}
	return -1; //������ ���� �Ȱɸ��� while���� �������Դٴ� ���� �������� ���Ѵٴ� ��
}
void init()
{
	cin >> k >> w >> h;

	memset(visited, -1, sizeof(visited));
	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= w; j++)
			cin >> map[i][j];
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	init();
	cout << bfs();

	return 0;
}