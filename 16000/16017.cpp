#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int a, b, c, d; cin >> a >> b >> c >> d;

	if (a == 8 || a == 9)
	{
		if (b == c)
		{
			if (d == 8 || d == 9)
			{
				cout << "ignore"; return 0;
			}
		}
	}

	cout << "answer";

	return 0;
}