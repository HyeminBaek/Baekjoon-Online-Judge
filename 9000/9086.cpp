#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t; cin >> t;

	for (t; t > 0; t--)
	{
		string s; cin >> s;
		cout << s[0] << s[s.length() - 1] << "\n";
	}

	return 0;
}