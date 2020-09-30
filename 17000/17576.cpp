#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	cin >> s;

	int n; cin >> n;

	int si = 0, ei = s.length() - 1;
	for (int i = 0; i < n; i++)
	{
		int a, b; cin >> a >> b;
		si += a;
		ei = si + (b - 1);
	}
	for (si; si <= ei; si++)
		cout << s[si];

	return 0;
}