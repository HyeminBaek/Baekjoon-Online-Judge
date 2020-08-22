#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int L, P, V, i = 1;
	while (cin >> L >> P >> V)
	{
		if (P == 0 && L == 0 && V == 0) break;
		int answer = ((V / P) * L);
		if (V % P <= L)
			answer += V % P;
		else
			answer += L;

		cout << "Case " << i << ": " << answer << "\n";
		i++;
	}

	return 0;
}