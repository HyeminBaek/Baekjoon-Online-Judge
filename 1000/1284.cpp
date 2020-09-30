#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	while (cin >> s)
	{
		if (s == "0") break;
		int sum = 2 + s.length() - 1;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == '1') sum += 2;
			else if (s[i] == '0') sum += 4;
			else sum += 3;
		}
		cout << sum << endl;
	}
	return 0;
}