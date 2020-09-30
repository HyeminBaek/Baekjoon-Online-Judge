#include <iostream>
#include <queue>
using namespace std;

int N, K;

int dx[] = { 2,-1,1 };
bool visited[100001];
queue<pair<int, int>> q;

int bfs()
{
	q.push(make_pair(N, 0));
	visited[N] == true;

	while (!q.empty())
	{
		int x = q.front().first;
		int time = q.front().second;
		q.pop();

		for (int k = 0; k < 3; k++)
		{
			if (x == K) return time;
			else
			{
				if (k > 0)
				{
					int nx = x + dx[k];
					if (nx >= 0 && nx <= 100000 && visited[nx] == false)
					{
						visited[nx] = true;
						q.push(make_pair(nx, time + 1));
					}
				}
				else
				{
					int nx = x * dx[k];
					if (nx <= 100000 && visited[nx] == false)
					{
						visited[nx] = true;
						q.push(make_pair(nx, time + 1));
					}
				}
			}
		}
	}
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;
}
int main()
{
	init();
	cout << bfs();

	return 0;
}