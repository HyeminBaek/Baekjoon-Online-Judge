#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct shark
{
	int fast, dir, size;
};
struct man
{
	int sy, sum;
};
bool xs(pair<pair<int, int>, shark>& p1, pair<pair<int, int>, shark>& p2)
{
	if (p1.first.first == p2.first.first) return p1.first.second < p2.first.second;
	return p1.first.first < p2.first.first;
}

int R, C;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };

man m;
shark map[101][101]; //빈곳은 -1-1-1

void movingShark()
{
	vector<pair<pair<int, int>, shark>> v; //상어정보 저장용

	shark arr[101][101];
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
			arr[i][j] = { -1,-1,-1 };
	}

	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			if (map[i][j].size != -1)
				v.push_back({ {i,j},map[i][j] });
		}
	}

	for (int i = 0; i < v.size(); i++)
	{
		int x = v[i].first.first, y = v[i].first.second;
		shark s = v[i].second;

		if (s.dir < 2) s.fast %= (2 * (R - 1));
		else s.fast %= (2 * (C - 1));

		for (int j = 0; j < s.fast; j++)
		{
			int nx = x + dx[s.dir], ny = y + dy[s.dir];

			if (0 < nx && nx <= R && 0 < ny && ny <= C)
			{
				x = nx, y = ny;
			}
			else
			{
				switch (s.dir)
				{
				case 0:
					s.dir = 1; break;
				case 1:
					s.dir = 0; break;
				case 2:
					s.dir = 3; break;
				case 3:
					s.dir = 2; break;
				}

				x = x + dx[s.dir], y = y + dy[s.dir];
			}
		}

		v[i].first.first = x, v[i].first.second = y, v[i].second = s;
		
		if (arr[x][y].size < s.size) arr[x][y] = s;
	}

	sort(v.begin(), v.end(), xs);

	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
			map[i][j] = arr[i][j];
	}
}
void moveNcatch()
{
	m.sy++;

	for (int i = 1; i <= R; i++)
	{
		if (map[i][m.sy].size != -1)
		{
			m.sum += map[i][m.sy].size;
			map[i][m.sy] = { -1,-1,-1 };

			break;
		}
	}
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int M; cin >> R >> C >> M;

	for (int i = 0; i <= R; i++)
	{
		for (int j = 0; j <= C; j++)
			map[i][j] = { -1,-1,-1 };
	}

	for (M; M > 0; M--)
	{
		int r, c, s, d, z; cin >> r >> c >> s >> d >> z;

		map[r][c] = { s,d - 1,z };
	}
	m = { 0,0 };
}
int main()
{
	init();
	while (m.sy < C)
	{
		moveNcatch();
		movingShark();
	}

	cout << m.sum;

	return 0;
}