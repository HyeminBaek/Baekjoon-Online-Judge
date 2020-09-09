#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	for (int i = 0; i < 3; i++)
	{
		string s; cin >> s;

		int len = 1, answer = 0;
		for (int j = 0; j < 7; j++)
		{
			if (s[j] == s[j + 1])
				len++;
			else
			{
				answer = max(answer, len); len = 1;
			}
		}
		answer = max(answer, len);
		cout << answer << endl;
	}

	return 0;
}