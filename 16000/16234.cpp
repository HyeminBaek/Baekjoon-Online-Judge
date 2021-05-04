#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int N, L, R;
int map[50][50],arr[50][50];
bool visited[50][50];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };


void merge(int cnt, int sum, vector<pair<int, int>> v)
{
	//cout << endl;
	int div = sum / cnt;
	for (int i = 0; i < v.size(); i++)
		arr[v[i].first][v[i].second] = div;
	/*
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
	*/
}
bool find(int i,int j)
{
	vector<pair<int, int>> v;
	if(!visited[i][j]) v.push_back({ i,j });

	bool flag = false;
	int cnt = 1, sum = map[i][j];
	queue<pair<int, int>> q;//x,y,cnt,sum
	q.push({ i,j });

	while (!q.empty())
	{
		int x = q.front().first, y = q.front().second;
		q.pop();
		
		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k], ny = y + dy[k];

			if (0 <= nx && nx < N && 0 <= ny && ny < N)
			{
				int dif = abs(map[x][y] - map[nx][ny]);

				if (!visited[nx][ny]&&L <= dif && dif <= R)
				{
					if (!visited[x][y]) visited[x][y] = true;

					flag = true;
					visited[nx][ny] = true;
					cnt += 1;
					sum += map[nx][ny];
					q.push({nx,ny});

					v.push_back({ nx,ny });
				}
			}
		}
	}
	if (flag) merge(cnt, sum, v);

	return flag;
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> L >> R;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> map[i][j];
	}
}
int main()
{
	init();

	int answer = 0;
	while (1) //루프 한 번이 하루
	{
		bool flag = false;
		memset(visited, false, sizeof(visited));
		memcpy(arr, map, sizeof(map));
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (find(i, j)) flag = true;
			}
		}

		if (!flag) break;
		else 
		{
			memcpy(map, arr, sizeof(arr)); answer += 1;
		}
	}

	cout << answer;

	return 0;
}