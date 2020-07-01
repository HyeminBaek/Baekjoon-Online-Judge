#include <iostream>
#include <string>
using namespace std;

bool check(char y, char x)
{
	if ('1' <= x && x <= '8' && 'A' <= y && y <= 'H') return true;
	else return false;
}

int main()
{
	int dx[] = { 0,0,-1,1,1,1,-1,-1 };
	int dy[] = { 1,-1,0,0,1,-1,1,-1 };

	int n;
	string king, stone;
	cin >> king >> stone >> n;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;

		if (s == "R")
		{
			if (check(king[0] + dy[0], king[1]))//킹이 움직일 수 있음
			{
				king[0] += dy[0];
				if (king[0] == stone[0] && king[1] == stone[1])//돌==왕
				{
					if (check(stone[0] + dy[0], stone[1])) //돌 움직일 수 있음
						stone[0] += dy[0];
					else
						king[0] -= dy[0];
				}
			}
		}
		else if (s == "L")
		{
			if (check(king[0] + dy[1], king[1]))
			{
				king[0] += dy[1];
				if (king[0] == stone[0] && king[1] == stone[1])
				{
					if (check(stone[0] + dy[1], stone[1]))
						stone[0] += dy[1];
					else
						king[0] -= dy[1];
				}
			}
		}
		else if (s == "B")
		{
			if (check(king[0], king[1] + dx[2]))
			{
				king[1] += dx[2];
				if (king[0] == stone[0] && king[1] == stone[1])
				{
					if (check(stone[0], stone[1] + dx[2]))
						stone[1] += dx[2];
					else
						king[1] -= dx[2];
				}
			}
		}
		else if (s == "T")
		{
			if (check(king[0], king[1] + dx[3]))
			{
				king[1] += dx[3];
				if (king[0] == stone[0] && king[1] == stone[1])
				{
					if (check(stone[0], stone[1] + dx[3]))
						stone[1] += dx[3];
					else
						king[1] -= dx[3];
				}
			}
		}
		else if (s == "RT")
		{
			if (check(king[0] + dy[4], king[1] + dx[4]))
			{
				king[0] += dy[4]; king[1] += dx[4];
				if (king[0] == stone[0] && king[1] == stone[1])
				{
					if (check(stone[0] + dy[4], stone[1] + dx[4]))
					{
						stone[0] += dy[4]; stone[1] += dx[4];
					}
					else
					{
						king[0] -= dy[4]; king[1] -= dx[4];
					}
				}

			}
		}
		else if (s == "LT")
		{
			if (check(king[0] + dy[5], king[1] + dx[5]))
			{
				king[0] += dy[5]; king[1] += dx[5];
				if (king[0] == stone[0] && king[1] == stone[1])
				{
					if (check(stone[0] + dy[5], stone[1] + dx[5]))
					{
						stone[0] += dy[5]; stone[1] += dx[5];
					}
					else
					{
						king[0] -= dy[5]; king[1] -= dx[5];
					}
				}
			}
		}
		else if (s == "RB")
		{
			if (check(king[0] + dy[6], king[1] + dx[6]))
			{
				king[0] += dy[6]; king[1] += dx[6];
				if (king[0] == stone[0] && king[1] == stone[1])
				{
					if (check(stone[0] + dy[6], stone[1] + dx[6]))
					{
						stone[0] += dy[6]; stone[1] += dx[6];
					}
					else
					{
						king[0] -= dy[6]; king[1] -= dx[6];
					}
				}
			}
		}
		else if (s == "LB")
		{
			if (check(king[0] + dy[7], king[1] + dx[7]))
			{
				king[0] += dy[7]; king[1] += dx[7];
				if (king[0] == stone[0] && king[1] == stone[1])
				{
					if (check(stone[0] + dy[7], stone[1] + dx[7]))
					{
						stone[0] += dy[7]; stone[1] += dx[7];
					}
					else
					{
						king[0] -= dy[7]; king[1] -= dx[7];
					}
				}
			}
		}
		//cout << king << "\n" << stone << "\n";
	}
	cout << king << "\n" << stone << "\n";

	return 0;
}