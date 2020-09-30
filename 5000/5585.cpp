#include <iostream>
using namespace std;

int main()
{
	int N; cin >> N;
	N = 1000 - N;

	int answer = 0;
	if (N >= 500)
	{
		answer += N / 500; N %= 500;
	}
	if (N >= 100)
	{
		answer += N / 100; N %= 100;
	}
	if (N >= 50)
	{
		answer += N / 50; N %= 50;
	}
	if (N >= 10)
	{
		answer += N / 10; N %= 10;
	}
	if (N >= 5)
	{
		answer += N / 5; N %= 5;
	}
	if (N < 5)
	{
		answer += N;
	}
	cout << answer;

	return 0;
}