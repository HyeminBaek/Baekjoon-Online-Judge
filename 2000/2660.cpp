#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
vector<int> v[51];
bool visited[51];
int answer[51];

void bfs(int i)
{
	queue<pair<int, int>> q;
	q.push({ i,0 });

	visited[i] = true;

	while (!q.empty())
	{
		int x = q.front().first, len = q.front().second; q.pop();
		answer[i] = len;

		for (int k = 0; k < v[x].size(); k++)
		{
			if (!visited[v[x][k]])
			{
				visited[v[x][k]] = true;
				q.push({ v[x][k],(len + 1) });
			}
		}
	}
}
int count(int minV)
{
	int cnt = 0;
	for (int i = 1; i <= N; i++)
	{
		if (minV == answer[i]) cnt++;
	}

	return cnt;
}
int findMinValue()
{
	int minV = answer[1];
	for (int i = 2; i <= N; i++)
	{
		if (minV > answer[i]) minV = answer[i];
	}

	return minV;
}
void print(int minV)
{
	for (int i = 1; i <= N; i++)
	{
		if (minV == answer[i]) cout << i << " ";
	}
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	int x, y;
	while (cin >> x >> y)
	{
		if (x == -1 && y == -1) break;
		v[x].push_back(y);
		v[y].push_back(x);
	}
}
int main()
{
	init();
	
	for (int i = 1; i <= N; i++)
	{
		memset(visited, false, sizeof(visited));
		bfs(i);
	}

	int minV = findMinValue();
	int cnt = count(minV);

	cout << minV << " " << cnt << "\n";

	print(minV);

	return 0;
}