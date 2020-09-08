#include <iostream>
using namespace std;

int main()
{
	int T; cin >> T;
	for (int i = 0; i < T; i++)
	{
		int N, M; cin >> N >> M;

		cout << 2 * M - N << " " << M - (2 * M - N) << endl;
	}

	return 0;
}