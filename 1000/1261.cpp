#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M;
int map[101][101];

int sol()
{
	int dist[101][101];
	memset(dist, 1000000, sizeof(dist));

	priority_queue <pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>> pq;
	pq.push({ 0,{0,0} }); dist[0][0] = 0;

	int dx[] = { 1,-1,0,0 };
	int dy[] = { 0,0,1,-1 };

	while (!pq.empty())
	{
		int x = pq.top().second.first, y = pq.top().second.second; pq.pop();

		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k], ny = y + dy[k];

			/*
			�� �κп��� Ǯ�̸� �����ؾ���.(https://huiung.tistory.com/110)
			ó���� v[x][y].push_back({i,j}); �������� �����ߴµ� ������ ����
			�׷��� ��� �����ؾ� �� �� ���� �������� �ô�.

			Ǯ�� 1. visited �迭�� �ξ�, �湮���� �ʾҴٸ�
			if (dist[nx][ny] > dist[x][y] + map[nx][ny]) ������ �����ϸ� �� �����ϰ� push
			-> ���� �������� �׽�Ʈ���̽� 2�� ��� 1����, (1,1)���� ����ε� min�� ������ �ȵ�
			Ǯ�� 2. visited �迭�� ���� ����
			-> �׷��� 1����

			�� �� �� Ǯ�� ����
			Ǯ�� 3. ���� pq�� greater�� �ȵΰ� ����ġ�� -�� ��Ҵ�
			->�׷��� 1����

   .		Ǯ�� 4. �˰��� N,M�� �ٲ㼭 �Է¹���, pq ������� greater�� �����غ�

			*/
			if (0 <= nx && nx < N && 0 <= ny && ny < M)
			{
				if (dist[nx][ny] > dist[x][y] + map[nx][ny])
				{
					dist[nx][ny] = dist[x][y] + map[nx][ny];
					pq.push({ dist[nx][ny],{nx,ny} });
				}
			}
		}
	}

	return dist[N - 1][M - 1];
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	swap(N, M);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			char c; cin >> c;
			map[i][j] = c - '0';
		}
	}
}
int main()
{
	init();
	cout << sol();

	return 0;
}