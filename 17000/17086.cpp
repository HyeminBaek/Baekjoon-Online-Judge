#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
int visited[51][51];
int arr[51][51];
int dx[] = { -1,1,0,0,1,-1,-1,1 };
int dy[] = { 0,0,1,-1,1,1,-1,-1 };

int bfs(int x,int y)
{
	queue<pair<int, int>> q; //�� 0���� bfs()�� ���Ӱ� �������ϱ� ����,�� ������ bfs ���鼭 �����Ÿ��� ����
	q.push(make_pair(x, y));

	visited[x][y] = 0;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (arr[x][y] == 1) return visited[x][y]; //�� ���� ������ �� bfs ���� �ȵǹǷ�

		for (int k = 0; k < 8; k++)
		{
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (0 <= nx && nx < N && 0 <= ny && ny < M)
			{
				if (visited[nx][ny] == -1)
				{
					visited[nx][ny] = visited[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		for(int j =0;j < M;j++)
			cin >> arr[i][j];

	int answer = -1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			memset(visited, -1, sizeof(visited)); //�Ź� ���ο� bfs�� ���⶧��
			if (arr[i][j] == 0) 
				answer = max(answer,bfs(i,j));
		}
	}

	cout << answer;

	return 0;
}