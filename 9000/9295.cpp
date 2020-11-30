#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;
	for (int i = 1; i <= T; i++)
	{
		int x, y; cin >> x >> y;

		cout << "Case " << i << ": " << x + y << '\n';
	}

	return 0;
}