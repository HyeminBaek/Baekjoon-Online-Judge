#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

struct s
{
	int x; int y;
};
int N, M;
long long gas;
int map[21][21];

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };

vector<pair<int, int>> p[401]; //�°��� �ִ� 400��
vector<int> over;//�̹� ó���� �� �°� �����

int bfs(int sx, int sy, int ex, int ey)
{
	queue<pair<int, int>> q;
	q.push({ sx,sy });

	int visited[21][21];
	memset(visited, -1, sizeof(visited));
	visited[sx][sy] = 0;

	while (!q.empty())
	{
		int x = q.front().first; int y = q.front().second;
		q.pop();

		if (x == ex && y == ey)
		{
			return visited[x][y];
		}
		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k], ny = y + dy[k];

			if (0 <= nx && nx < N && 0 <= ny && ny < N)
			{
				if (map[nx][ny] == 0 && visited[nx][ny] == -1)
				{
					visited[nx][ny] = visited[x][y] + 1;
					q.push({ nx,ny });
				}
			}
		}
	}
	return -1;
}
int findP(int x, int y) //�ִ� ����� �մ� ã��
{
	vector<pair<pair<int, int>, pair<int, int>>> pq; //�ִܰŸ�,��,��,�մԹ�ȣ

	for (int i = 1; i <= M; i++)
	{
		if (find(over.begin(), over.end(), i) != over.end()) continue; //�̹� �°��� ó���Ǿ�����
		int result = bfs(x, y, p[i][0].first, p[i][0].second);

		if (result == -1) return -1;
		pq.push_back({ { result,p[i][0].first },{ p[i][0].second,i } });
	}

	sort(pq.begin(), pq.end());

	return pq.front().second.second;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> gas;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> map[i][j];
	}

	int taxi_x, taxi_y; cin >> taxi_x >> taxi_y;
	taxi_x--; taxi_y--;
	map[taxi_x][taxi_y] = -1;//�ýô� �� �󿡼� -1�� ǥ���� ����

	for (int i = 1; i <= M; i++)
	{
		int p_sx, p_sy, p_ex, p_ey; cin >> p_sx >> p_sy >> p_ex >> p_ey;

		p[i].push_back({ p_sx - 1,p_sy - 1 }); p[i].push_back({ p_ex - 1,p_ey - 1 });
	}

	for (int i = 0; i<M; i++)
	{
		//������ �� ������ ���
		if (gas < 0) break;

		//�ִ� �Ÿ� �մ� ã��
		int idx = findP(taxi_x, taxi_y);

		//���� �ýð� �� ���� ���� �մ��� �ִٸ�
		if (idx < 0)
		{
			cout << -1;	 return 0;
		}

		gas -= bfs(taxi_x, taxi_y, p[idx][0].first, p[idx][0].second); // ���� �Ҹ� 

																	   //�°��� �ִ� ������ �ý� �̵�
		map[taxi_x][taxi_y] = 0; map[p[idx][0].first][p[idx][0].second] = -1;
		taxi_x = p[idx][0].first; taxi_y = p[idx][0].second;

		//�ýð� ���������� ��
		int temp = bfs(taxi_x, taxi_y, p[idx][1].first, p[idx][1].second);
		//�ýð� ���������� �����ų� ���ٰ� ���ᰡ �ٴڳ�
		if (temp == -1 || gas < temp)
		{
			cout << -1; return 0;
		}
		gas -= temp;
		gas += (2 * temp);

		over.push_back(idx);//���������� �� �°��� ������

							//�������� �ý� �̵�
		map[taxi_x][taxi_y] = 0; map[p[idx][1].first][p[idx][1].second] = -1;
		taxi_x = p[idx][1].first; taxi_y = p[idx][1].second;
	}

	if (over.size() == M)	cout << gas;
	else cout << -1;

	return 0;
}