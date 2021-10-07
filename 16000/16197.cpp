#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

/*
* 1. 동전이 이동하려는 칸이 벽이면, 동전은 이동하지 않는다.
* 2. 동전이 이동하려는 방향에 칸이 없으면(out of bounds) 동전은 보드 바깥으로 떨어진다.
* 3. 이동하려는 칸에 동전이 있는 경우에도 한 칸 이동한다.
*/
const int MAX_SIZE = 20;

struct coin
{
	int x, y;
};
struct mov
{
	coin coin1, coin2;
	int cnt;
};

int N, M, answer;
char arr[MAX_SIZE][MAX_SIZE];

coin c1, c2;

//4개의 버튼
int dir[][2] = { {-1,0},{1,0},{0,1},{0,-1} };

bool isRange(int nx, int ny)
{
	if (0 <= nx && nx < N && 0 <= ny && ny < M) return true;

	return false;
}
void bfs()
{
	queue<mov> q;
	q.push({c1,c2,0});

	//bool visited[MAX_SIZE][MAX_SIZE][2] = { false, };

	while (!q.empty())
	{
		coin coin1 = q.front().coin1, coin2 = q.front().coin2;
		int cnt = q.front().cnt; q.pop();

		//버튼을 10번보다 많이 눌러야 한다면
		if (cnt > 10) continue; //실수

		for (int k = 0;k < 4;k++)
		{
			int nx1 = coin1.x + dir[k][0], ny1 = coin1.y + dir[k][1];
			int nx2 = coin2.x + dir[k][0], ny2 = coin2.y + dir[k][1];
			//cout << k<<" "<<nx1 << " " << ny1 << " " << nx2 << " " << ny2 << " " << cnt << endl;
			bool range1 = isRange(nx1, ny1), range2 = isRange(nx2, ny2);
			if (!range1 && !range2) continue;
			else if (range1 && range2)
			{
				//if (!visited[nx1][ny1][0] || !visited[nx2][ny2][1]) //not visited
				//{
					coin tmp1 = coin1, tmp2 = coin2;

					if (arr[nx1][ny1] != '#') tmp1.x = nx1, tmp1.y = ny1;
					if (arr[nx2][ny2] != '#') tmp2.x = nx2, tmp2.y = ny2;

					//visited[nx1][ny1][0] = true; visited[nx2][ny2][1] = true;
					q.push({ tmp1,tmp2,cnt + 1 }); 
				//}
			}
			else answer = (answer > cnt + 1) ? cnt + 1 : answer;
		}
	}
}
void solution()
{
	bfs();

	if (answer == 987654321||answer>10) answer = -1;
	cout << answer;
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	bool flag = false;
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < M;j++)
		{
			cin >> arr[i][j];

			if (arr[i][j] == 'o')
			{
				arr[i][j] = '.';

				if (!flag)
				{
					flag = true; c1.x = i, c1.y = j;
				}
				else
				{
					c2.x = i, c2.y = j;
				}
			}
		}
	}
	answer = 987654321;
}
int main()
{
	init();
	solution();

	return 0;
}
