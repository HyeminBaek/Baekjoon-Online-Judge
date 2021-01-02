#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;
	int cur; cin >> cur;

	int max = 0;
	for (int i = 0; i < n; i++)
	{
		int a, b; cin >> a >> b;

		cur += a; cur -= b;
		if (cur < 0)
		{
			cout << 0; return 0;
		}
		max=(max<cur)?cur:max;
	}
	cout << max;

	return 0;
}