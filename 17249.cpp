#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s; cin >> s;

	int left = 0, right = 0, idx = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(') 
		{
			idx = i; break;
		}
		if (s[i] == '@')
			left++;
	}
	for (int i = idx + 2; i < s.length(); i++)
	{
		if (s[i] == '@')
			right++;
	}
	cout << left << " " << right;

	return 0;
}