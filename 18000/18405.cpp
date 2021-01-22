#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct virus
{
	int vnum; int vx; int vy; 
	int vtime; //���̷��� ��ȣ,���̷�����ǥ,�ð�
};
int N, S, X, Y;
int map[200][200];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };

queue<virus> q;//bfs�� �������� ť

bool compare(virus& v1, virus& v2)
{
	return v1.vnum < v2.vnum;
}
void bfs()
{
	while (!q.empty())
	{
		int num = q.front().vnum, x = q.front().vx, y = q.front().vy;
		int time = q.front().vtime; q.pop();

		if (time == S) return;

		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k], ny = y + dy[k];
			if (0 <= nx && nx < N && 0 <= ny && ny < N)
			{
				if (map[nx][ny] == 0)
				{
					map[nx][ny] = num;
					q.push({ num,nx,ny,time + 1 });
				}
			}
		}
	}
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int K; cin >> N >> K;

	vector<virus> v; //���̷������� ��ǥ�� �����
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];

			if (map[i][j] != 0)
				v.push_back({ map[i][j],i,j,0 });
		}
	}

	cin >> S >> X >> Y;
	sort(v.begin(), v.end(),compare);
	
	for (int i = 0; i < v.size(); i++)
		q.push(v[i]);
}
int main()
{
	init();
	bfs();

	cout << map[X - 1][Y - 1];

	return 0;
}