#include <iostream>
#include <string>
using namespace std;

int main()
{
	int T; cin >> T;
	for (int i = 0; i < T; i++)
	{
		int x; cin >> x;
		int temp = 0;
		int y = x;
		while (x > 0)
		{
			temp += x % 10;
			temp *= 10;
			x /= 10;
		}
		temp /= 10;
		temp += y;
		string s = to_string(temp);
		bool flag = false;
		for (int i = 0; i < s.length() / 2; i++)
		{
			if (s[i] != s[s.length() - 1 - i])
			{
				flag = true; break;
			}
		}
		if (flag)
			cout << "NO\n";
		else
			cout<<"YES\n";
	}
	return 0;
}