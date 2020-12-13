#include <iostream>
using namespace std;

int main()
{
	int N; cin >> N;

	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		int C, K; cin >> C >> K;
		answer += C * K;
	}
	cout << answer;

	return 0;
}