#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int N;
const int MAX_SIZE = 5;

int dx[] = { 0,1 };
int dy[] = { 1,0 };

char arr[MAX_SIZE][MAX_SIZE];
int min_dp[MAX_SIZE][MAX_SIZE]; //�ּڰ� �����
int max_dp[MAX_SIZE][MAX_SIZE]; //dp[i][j] = (i,j)�϶��� ���� �ִ�

void bfs()
{
	queue<pair<pair<int, int>,char>> q; //���� ��ǥ�� ������
	q.push({ { 0, 0 },' ' });
	min_dp[0][0] = arr[0][0]-'0';
	max_dp[0][0] = arr[0][0]-'0';

	while (!q.empty())
	{
		int x = q.front().first.first, y = q.front().first.second;
		char oper = q.front().second;	q.pop();

		for (int k = 0; k < 2; k++)
		{
			int nx = x + dx[k], ny = y + dy[k];

			if (0 <= nx && nx < N && 0 <= ny && ny < N)
			{
				if (arr[nx][ny] == '+' || arr[nx][ny] == '-' || arr[nx][ny] == '*')//���� ��ġ�� �������� ���
				{
					min_dp[nx][ny] = min(min_dp[nx][ny], min_dp[x][y]); //�ܼ� �� ����
					max_dp[nx][ny] = max(max_dp[nx][ny], max_dp[x][y]);
					q.push({ {nx,ny},arr[nx][ny] });//�����ڸ� �����ؼ� ť�� ����
				}
				else
				{
					if (oper != ' ') //ť�� �����ڰ� ����ִ� ���
					{
						if (oper == '+') //������ ����� ������ ����� ���� ��
						{
							min_dp[nx][ny] = min(min_dp[nx][ny], min_dp[x][y] + (arr[nx][ny] - '0'));
							max_dp[nx][ny] = max(max_dp[nx][ny], max_dp[x][y] + (arr[nx][ny] - '0'));
							q.push({ { nx,ny },' ' });
						}
						else if (oper == '-')
						{
							min_dp[nx][ny] = min(min_dp[nx][ny], min_dp[x][y] - (arr[nx][ny] - '0'));
							max_dp[nx][ny] = max(max_dp[nx][ny], max_dp[x][y] - (arr[nx][ny] - '0'));
							q.push({ { nx,ny },' ' });
						}
						else if (oper == '*')
						{
							min_dp[nx][ny] = min(min_dp[nx][ny], min_dp[x][y] * (arr[nx][ny] - '0'));
							max_dp[nx][ny] = max(max_dp[nx][ny], max_dp[x][y] * (arr[nx][ny] - '0'));
							q.push({ { nx,ny },' ' });
						}
					}
				}
			}
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
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
	}

	//���ǿ��� ������� �� ���� ������ �ִ�,�ּҷ� �ʱ�ȭ
	memset(min_dp, 9999, sizeof(min_dp));
	memset(max_dp, -9999, sizeof(max_dp));

	bfs();
	
	cout << max_dp[N - 1][N - 1] << " " << min_dp[N - 1][N - 1];

	return 0;
}