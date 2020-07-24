#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int N, num;
bool visited[26][26];
int map[26][26];

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
vector<int> v;

void bfs(int i, int j)
{
	queue<pair<int, int>> q;
	q.push(make_pair(i, j));
	visited[i][j] = true; num = 0;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		num++;
		q.pop();

		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k]; int ny = y + dy[k];

			if (0 <= nx && nx < N && 0 <= ny && ny < N)
			{
				if (visited[nx][ny] == false && map[nx][ny] == 1)
				{
					visited[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			char c; cin >> c;
			map[i][j] = c - '0';
		}
	}
}
int main()
{
	init();

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visited[i][j] == 0 && map[i][j] == 1)
			{
				bfs(i, j); v.push_back(num);
			}
		}
	}
	cout << v.size() << endl;

	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << endl;

	return 0;
}