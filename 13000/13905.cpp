#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// max 경로 중 min 값
int N, s, e;
vector<pair<int, int>> v[100001]; //노드, 웨이트
bool visited[100001];

bool bfs(int weight)
{
	for (int i = 1; i <= N; i++) visited[i] = false;

	queue<int> q;	q.push(s);	visited[s] = true;

	while (!q.empty())
	{
		int x = q.front();	q.pop();

		if (x == e) return true;
		
		for (int i = 0; i < v[x].size(); i++)
		{
			int nx = v[x][i].first;
			if (!visited[nx] && v[x][i].second >= weight)
			{
				visited[nx] = true;
				q.push(nx);
			}
		}
	}
	return false;
}
int sol()
{
	int low = 1, high = 1000000, mid = (low + high) / 2;
	while (low <= high)
	{
		//cout << low << " " << mid << " " << high << endl;
		mid = (low + high) / 2;

		if (bfs(mid))	low = mid + 1; 
		else high = mid - 1;
	}
	if (high == -1) high = 0;
	return high;
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int M; cin >> N >> M >> s >> e;

	for (M; M > 0; M--)
	{
		int h1, h2, k; cin >> h1 >> h2 >> k;

		v[h1].push_back({ h2,k });
		v[h2].push_back({ h1, k });
	}
}
int main()
{
	init();
	cout << sol();

	return 0;
}
