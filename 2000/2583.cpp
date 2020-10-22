#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int M, N;
bool map[100][100];
bool visited[100][100];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
vector<int> answer;

int bfs(int i,int j)
{
	queue<pair<int, int>> q;
	q.push({ i,j }); visited[i][j] = true;

	int size = 0;
	while (!q.empty())
	{
		int x = q.front().first, y = q.front().second;
		size++; q.pop();

		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k], ny = y + dy[k];
			if (0 <= nx && nx < M && 0 <= ny && ny < N)
			{
				if (!map[nx][ny] && !visited[nx][ny])
				{
					q.push({nx,ny});
					visited[nx][ny] = true;
				}
			}
		}
	}
	return size;
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int K; cin >> M >> N >> K;
	for (int i = 0; i < K; i++)
	{
		int sx, sy, ex, ey; cin >> sy >> sx >> ey >> ex;
		for (int i = sx; i < ex; i++)
		{
			for (int j= sy; j < ey; j++)
			{
				map[i][j] = true;
			}
		}
	}
}
int main()
{
	init();
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!map[i][j] && !visited[i][j])
				answer.push_back(bfs(i, j));
		}
	}

	cout << answer.size() << "\n";
	sort(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << " ";
	
	return 0;
}