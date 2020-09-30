#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	long long* Narr = new long long[N];
	for (int i = 0; i < N; i++)
		cin >> Narr[i];

	int M; cin >> M;
	long long* Marr = new long long[M];
	for (int i = 0; i < M; i++)
		cin >> Marr[i];

	sort(Narr, Narr + N);
	for (int i = 0; i < M; i++)
	{
		cout << upper_bound(Narr, Narr + N, Marr[i]) - lower_bound(Narr, Narr + N, Marr[i]) << " ";
	}

	return 0;
}