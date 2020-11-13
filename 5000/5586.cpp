#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s;
	cin >> s;

	int joi = 0, ioi = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == 'J')
		{
			if (s.substr(i, 3) == "JOI")
				joi++;
		}
		else if (s[i] == 'I')
		{
			if (s.substr(i, 3) == "IOI")
				ioi++;
		}
	}

	cout << joi << "\n" << ioi;

	return 0;
}