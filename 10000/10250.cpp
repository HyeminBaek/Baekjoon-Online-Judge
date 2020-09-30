#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int h, w, n;
		cin >> h >> w >> n;

		int temp = 1;//호수를 세기 위한 변수
		while (n > h)
		{
			n -= h;//모든 층의 temp호에 배정됨
			temp++;//다음 호에 사람을 배정하기 시작
		}

		if (temp < 10)
			cout << n << "0" << temp << "\n";
		else
			cout << n << temp << "\n";
	}

	return 0;
}