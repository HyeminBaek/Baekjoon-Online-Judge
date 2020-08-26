#include <iostream>
using namespace std;

int main()
{
	int N; cin >> N;

	int answer = 0, sec = 0;
	while (N != 0)
	{
		sec++; answer++;
		if (N < sec)
			sec = 1;

		N -= sec;
	}
	cout << answer;

	return 0;
}