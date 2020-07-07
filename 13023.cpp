#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

//������ "DFS�� �ð��ʰ��� �� ��� ���������� �ִ��� ���� ����. ������ �󸶳� �־�� ����
//        �𸣱� ������ �� ��� DFS�� ���� �� ������"
int N, M;
int visited[2001];
vector<int> v[2001];

//void ���� �� �ð� �ʰ���
int dfs(int x, int sum)
{
	if (sum >= 5)
		return 1;
	for (int i = 0; i < v[x].size(); i++)
	{
		if (visited[v[x][i]] == -1)
		{
			visited[v[x][i]] = 0;

			if (dfs(v[x][i], sum + 1) == 1) return 1;
			visited[v[x][i]] = -1;
		}
	}
	return 0;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int x, y;
		cin >> x >> y;

		v[x].push_back(y); v[y].push_back(x);
	}
	for (int i = 0; i < N; i++)
	{
		memset(visited, -1, sizeof(visited));
		if (dfs(i, 0) == 1)
		{
			cout << 1;
			return 0;
		}
	}

	cout << 0;

	return 0;
}