#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int R, C; char chess[50][50];
vector<pair<int, int>> wrong;

int num(int row, int col, bool stp) //stp 변수는 w로 시작할 때 0,b로 시작할 때 1
{
	int temp = 0;
	for (int i = row; i < row + 8; i++)
	{
		for (int j = col; j < col + 8; j++)
		{
			if (i % 2 == 0)
			{
				if (j % 2 == 0)
				{
					if (!stp && chess[i][j] != 'W')   temp++;
					else if (stp && chess[i][j] != 'B') temp++;
				}
				else
				{
					if (!stp && chess[i][j] != 'B') temp++;
					else if (stp && chess[i][j] != 'W') temp++;
				}
			}
			else
			{
				if (j % 2 == 1)
				{
					if (!stp && chess[i][j] != 'W') temp++;
					else if (stp && chess[i][j] != 'B') temp++;
				}
				else
				{
					if (!stp && chess[i][j] != 'B') temp++;
					else if (stp && chess[i][j] != 'W') temp++;
				}
			}
		}
	}
	return temp;
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
			cin >> chess[i][j];
	}
}
int main()
{
	init();

	int answer = 100;
	for (int i = 0; i <= R - 8; i++)
	{
		for (int j = 0; j <= C - 8; j++)
		{
			int temp = min(num(i, j, true), num(i, j, false));
			answer = min(answer, temp);
		}
	}

	cout << answer;

	return 0;
}