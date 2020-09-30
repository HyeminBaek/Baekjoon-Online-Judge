#include <iostream>
#include <string>
using namespace std;

int main()
{
	int T; cin >> T;
	for (int i = 0; i < T; i++)
	{
		int n; cin >> n;
		string s; cin >> s;

		for (int j = 0; j < s.length(); j++)
		{
			if (j == n - 1) continue;
			cout << s[j];
		}
		cout << endl;
	}
	return 0;
}