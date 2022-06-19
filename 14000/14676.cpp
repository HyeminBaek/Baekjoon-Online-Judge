#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int SIZE = 100001;

int N, K;

int visited[SIZE], parent[SIZE];

vector<int> edge[SIZE]; //본인, 부모

bool solution()
{
	bool answer = true;
	for (int i = 0; i < K; i++)
	{
		int com, a; cin >> com >> a;

		if (!answer) continue;

		if (com == 1)
		{
			bool flag = true;
			
			if (parent[a] != 0) flag = false;

			if (flag)
			{
				if (visited[a] == 0)
				{
					for (int next : edge[a])
					{
						if (parent[next] == 0) continue;
						parent[next]--;
					}
				}
				visited[a]++;
			}
			else answer = false;
		}
		else
		{
			if (visited[a] > 0) visited[a]--;
			else answer = false;

			if (visited[a] == 0)
			{
				for (int next : edge[a])
					parent[next]++;
			}
		}
	}
	return answer;
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int M; cin >> N >> M >> K;

	for (int i = 0; i < M; i++)
	{
		int x, y; cin >> x >> y;
		edge[x].push_back(y);
		parent[y]++;
	}
}
int main()
{
	init();

	bool result = solution();
	if (result) cout << "King-God-Emperor";
	else cout << "Lier!";

	return 0;
}
