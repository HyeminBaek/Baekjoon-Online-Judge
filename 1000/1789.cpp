#include <iostream>
using namespace std;

int main()
{
	long long S; cin >> S;

	long long N = 1;
	for (N; N < S; N++)
	{
		if (N*(N + 1) / 2 >= S) break;
	}

	if (N*(N + 1) / 2 == S) cout << N;
	else cout << N - 1;

	return 0;
}