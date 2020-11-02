#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	cin >> s;

	int answer = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
			answer++;
	}
	cout << answer;

	return 0;
}