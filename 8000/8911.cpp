#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct turtle
{
	int x; int y; //현재 위치를 찍기 위한 변수
	int dirX; int dirY; //방향을 위한 변수 -> 동 dirX = 1,dirY=0 서 X=-1,Y=0 남 X=0,Y=-1 북 X=0,Y=1
};
void move(turtle t,string s)
{
	int minX = 0, maxX = 0, minY = 0, maxY = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == 'F')
		{
			if (t.dirX == 1 && t.dirY == 0)	t.x++;
			else if (t.dirX == -1 && t.dirY == 0) t.x--;
			else if (t.dirX == 0 && t.dirY == -1) t.y--;
			else if (t.dirX == 0 && t.dirY == 1) t.y++;
		}
		else if (s[i] == 'B')
		{
			if (t.dirX == 1 && t.dirY == 0)	t.x--;
			else if (t.dirX == -1 && t.dirY == 0) t.x++;
			else if (t.dirX == 0 && t.dirY == -1) t.y++;
			else if (t.dirX == 0 && t.dirY == 1) t.y--;
		}
		else if (s[i] == 'L')
		{
			if (t.dirX == 1 && t.dirY == 0)	t.dirX = 0, t.dirY = 1;
			else if (t.dirX == -1 && t.dirY == 0) t.dirX = 0, t.dirY = -1;
			else if (t.dirX == 0 && t.dirY == -1) t.dirX = 1, t.dirY = 0;
			else if (t.dirX == 0 && t.dirY == 1) t.dirX = -1, t.dirY = 0;
		}
		else if (s[i] == 'R')
		{
			if (t.dirX == 1 && t.dirY == 0)	t.dirX = 0, t.dirY = -1;
			else if (t.dirX == -1 && t.dirY == 0) t.dirX = 0, t.dirY = 1;
			else if (t.dirX == 0 && t.dirY == -1) t.dirX = -1, t.dirY = 0;
			else if (t.dirX == 0 && t.dirY == 1) t.dirX = 1, t.dirY = 0;
		}
		minX = (minX > t.x) ? t.x : minX; minY = (minY > t.y) ? t.y : minY;
		maxX = (maxX < t.x) ? t.x : maxX; maxY = (maxY < t.y) ? t.y : maxY;
	}

	cout << (abs(maxX) + abs(minX))*(abs(maxY) + abs(minY)) << "\n";
}
void init()
{
	string s; cin >> s;

	turtle t;
	t.x = 0, t.y = 0, t.dirX = 0, t.dirY = 1; //북쪽 방향을 보는 거북이

	move(t,s);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;
	for (int i = 0; i < T; i++)
	{
		init();
	}

	return 0;
}