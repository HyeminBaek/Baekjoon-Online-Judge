#include <iostream>
#include <algorithm>
using namespace std;

int init(int x)
{
	int y = x;
	while (y > 0)
	{
		if (y < 10)
		{
			x += y;   y = 0;
		}
		else
		{
			x += y % 10; y /= 10;
		}
	}
	return x;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;

	int answer = 0;
	for (int i = N; i > 0; i--)
	{
		if (init(i) == N)
		{
			if (answer == 0)   answer = i;
			else   answer = min(answer, i);
		}
	}

	cout << answer;

	return 0;
}