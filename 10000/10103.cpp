#include <iostream>
using namespace std;

int com(int a, int b)
{
	if (a < b)
		return b;
	else
		return 0;
}
int main()
{
	int n; cin >> n;
	int c = 100, s = 100;

	for (int i = 0; i < n; i++)
	{
		int a, b; cin >> a >> b;
		c -= com(a, b);
		s -= com(b, a);
	}
	cout << c << "\n" << s;

	return 0;
}