#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s; cin >> s;

	string answer = "";
	for (int i = 0; i < s.length(); i++)
	{
		if (i == 0 || (i > 0 && s[i - 1] == '-'))
			answer += s[i];
	}
	cout << answer;

	return 0;
}