#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s; cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= 97)
			s[i] = toupper(s[i]);
		else
			s[i] = tolower(s[i]);
	}
	cout << s;

	return 0;
}