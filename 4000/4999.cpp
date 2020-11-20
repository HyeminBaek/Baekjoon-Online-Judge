#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1, s2; cin >> s1 >> s2;
	string answer = (s1.length() >= s2.length()) ? "go" : "no";
	cout << answer;

	return 0;
}