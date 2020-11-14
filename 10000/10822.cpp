#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s; cin >> s;

	int sum = 0;
	string temp = "";
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == ',')
		{
			sum += stoi(temp);
			temp = "";
		}
		else
			temp += s[i];
	}
	sum += stoi(temp);
	cout << sum;

	return 0;
}