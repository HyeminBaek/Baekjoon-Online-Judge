#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

int N;
bool flag;
vector<string> v;
bool visited[100];

void dfs(int x,int leng)
{
	if (leng == N)
	{
		flag = true;
		return;
	}
	if (flag) return;
	for (int i = 0; i < v.size(); i++)
	{
		if (!visited[i] && v[i][0] == v[x].back())
		{
			visited[i] = true;
			dfs(i, leng + 1);
			if (flag) return;
			visited[i] = false;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		string s; cin >> s;
		v.push_back(s);
	}

	for (int i = 0; i < N; i++)
	{
		if (flag) break;
		memset(visited, false, sizeof(visited));
		visited[i] = true;
		dfs(i, 1);
	}

	if (flag) cout << 1;
	else cout << 0;

	return 0;
}