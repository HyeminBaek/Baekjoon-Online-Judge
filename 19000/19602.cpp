#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int S, M, L; cin >> S >> M >> L;

	int answer = S + (2 * M) + (3 * L);

	if (answer >= 10) cout << "happy";
	else cout << "sad";

	return 0;
}