#include <iostream>
#include <set>
#include <vector>
#include <cstring>
using namespace std;

set<int> s;
vector<int> v[501];
bool visited[501];

void dfs(int x,int num)
{
	visited[x] = true;
	if (num == 2)
	{
		s.insert(x); return;
	}
	for (int i = 0; i < v[x].size(); i++)
	{
		if (!visited[v[x][i]])
		{
			dfs(v[x][i], num + 1);
			visited[v[x][i]] = false;
		}
	}
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M; cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b; cin >> a >> b;
		v[a].push_back(b); v[b].push_back(a);
		if (a == 1)
			s.insert(b);
	}
}
int main()
{
	init();
	dfs(1, 0);
	cout << s.size();

	return 0;
}