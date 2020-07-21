#include <iostream>
#include <vector>
using namespace std;

vector<int> v[100001];
bool visited[100001];
int answer[100001];

void dfs(int x)
{
	visited[x] = true;

	for (int i = 0; i < v[x].size(); i++)
	{
		if (visited[v[x][i]] == false)
		{
			dfs(v[x][i]);
			answer[v[x][i]] = x;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 1; i < N; i++)
	{
		int a, b;
		cin >> a >> b;

		v[a].push_back(b); v[b].push_back(a);
	}

	dfs(1);

	for (int i = 2; i <= N; i++)
		cout << answer[i] << "\n";

	return 0;
}