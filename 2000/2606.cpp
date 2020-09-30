#include <iostream>
#include <vector>
using namespace std;

vector<int> v[101];
bool visited[101];

void dfs(int x, int& s)
{
	visited[x] = true;

	for (int i = 0; i < v[x].size(); i++)
	{
		if (!visited[v[x][i]])
		{
			s++;
			dfs(v[x][i], s);
		}
	}
}
int main()
{
	int c, r; cin >> c >> r;

	for (int i = 0; i < r; i++)
	{
		int x, y; cin >> x >> y;
		v[x].push_back(y); v[y].push_back(x);
	}

	int sum = 0;
	dfs(1, sum);
	cout << sum;

	return 0;
}