#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int ans; //정답 변수
int N, M, K;
int arr[21][21];
int dice[6] = { 2,4,1,3,5,6 };//2-4-1-3-5-6 위-왼쪽-천장-오른쪽-아래-바닥
int dir[4][2] = { {-1,0},{0,-1},{1,0},{0,1} }; //반시계방향 북서남동
int x = 1, y = 1, d = 3; //(x,y), 현재 방향 동쪽

void rotateDice()
{
	int tmp[6] = { 0, };
	if (d == 0)//북
	{
		tmp[0] = dice[2], tmp[1] = dice[1], tmp[2] = dice[4],
		tmp[3] = dice[3], tmp[4] = dice[5], tmp[5] = dice[0];
	}
	else if (d == 1)//서
	{
		tmp[0] = dice[0], tmp[1] = dice[2], tmp[2] = dice[3],
		tmp[3] = dice[5], tmp[4] = dice[4], tmp[5] = dice[1];
	}
	else if (d == 2)//남
	{
		tmp[0] = dice[5], tmp[1] = dice[1], tmp[2] = dice[0],
		tmp[3] = dice[3], tmp[4] = dice[2], tmp[5] = dice[4];
	}
	else//동
	{
		tmp[0] = dice[0], tmp[1] = dice[5], tmp[2] = dice[1],
		tmp[3] = dice[2], tmp[4] = dice[4], tmp[5] = dice[3];
	}

	for (int i = 0;i < 6;i++) dice[i] = tmp[i];
}
int score()
{
	int cnt = 1;
	bool visited[21][21] = { false, };

	queue<pair<int, int>> q;
	q.push({ x,y }); visited[x][y] = true;

	while (!q.empty())
	{
		int cx = q.front().first, cy = q.front().second;
		q.pop();

		for (int k = 0;k < 4;k++)
		{
			int nx = cx + dir[k][0], ny = cy + dir[k][1];
			if (1 <= nx && nx <= N && 1 <= ny && ny <= M)
			{
				if (arr[x][y] == arr[nx][ny] && !visited[nx][ny])
				{
					visited[nx][ny] = true;
					q.push({ nx,ny });
					cnt += 1;
				}
			}
		}
	}

	return cnt * arr[x][y];
}
void movingDice()
{
	/*
	* 해당 함수에서 한 칸 굴러가기 + 전개도 변경하기를 수행할 것
	* 굴러간 다음 전개도를 변경한 후 점수획득 함수 호출 -> A와 B 비교 후 x,y,d 값 변경
	*/ 
	int nx = x + dir[d][0], ny = y + dir[d][1];
	if (1 > nx || nx > N || 1 > ny || ny > M)
	{
		if (d == 0) d = 2;
		else if (d == 1) d = 3;
		else if (d == 2) d = 0;
		else d = 1;

		nx = x + dir[d][0], ny = y + dir[d][1];
	}

	x = nx, y = ny;

	//전개도 변경 로직
	rotateDice();

	ans+=score();

	if (arr[x][y] > dice[5])//B>A
	{
		d += 1;
		if (d == 4) d = 0;
	}
	else if (arr[x][y] < dice[5])//B<A
	{
		d -= 1;
		if (d == -1) d = 3;
	}
}
void solution()
{
	while (K-->0)
	{
		movingDice();
	}

	cout << ans;
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> K;
	for (int i = 1;i <= N;i++)
	{
		for (int j = 1;j <= M;j++)
			cin >> arr[i][j];
	}
}
int main()
{
	init();
	solution();

	return 0;
}
