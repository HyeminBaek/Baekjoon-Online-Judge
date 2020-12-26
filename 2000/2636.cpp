#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
bool map[100][100];
int visited[100][100];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };

int bfs()
{
	queue<pair<int, int>> q;
	q.push({ 0,0 }); visited[0][0] = 0;
	//bfs ���鼭 ���� Ž��
	while (!q.empty())
	{
		int x = q.front().first; int y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k], ny = y + dy[k];

			if (0 <= nx && nx < N && 0 <= ny && ny < M)
			{
				if (visited[nx][ny] == -1 && !map[nx][ny])
				{
					visited[nx][ny] = 0;
					q.push({ nx,ny });
				}
			}
		}
	}
	//���� ��ó ġ�� ����
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (visited[i][j]==0)
			{
				for (int k = 0; k < 4; k++)
				{
					int nx = i + dx[k], ny = j + dy[k];
					if (0 <= nx && nx < N && 0 <= ny && ny < M)
					{
						if (visited[nx][ny] == -1 && map[nx][ny])
						{
							map[nx][ny] = 0;
						}
					}
				}
			}
		}
	}

	//ġ�� ���� ����
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j])
				count++;
		}
	}

	return count;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	int remain = 0, time = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			if (map[i][j]) remain++;
		}
	}

	while (true)
	{
		memset(visited, -1, sizeof(visited));
		int temp = bfs(); time++;
		if(temp>0)
			remain = temp;
		else // ���� ġ�� ������ 0�̸� ���� �������� �ʰ� ���� �� ����
		{
			cout << time << "\n" << remain;
			break;
		}
	}
	
	return 0;
}