#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	cin >> s;

	int num = 0;

	for (int i = 0; i < s.length(); i++)
	{
		switch (s[i])
		{
		case 'c':
				if ((i + 1 != s.length())&&(s[i + 1] == '='))
				{
					i++; num++;
				}
				else if ((i + 1 != s.length()) && (s[i + 1] == '-'))
				{
					i++; num++;
				}
			else
				num++;
			break;
		case 'd':
			if ((i + 2 != s.length()) && (s[i + 1] == 'z') && (s[i + 2] == '='))
			{
				i += 2; num++;
			}
			else if ((i + 1 != s.length()) && (s[i + 1] == '-'))
			{
				i++; num++;
			}
			else
				num++;
			break;
		case 'l':
			if ((i + 1 != s.length()) && (s[i + 1] == 'j'))
			{
				i++; num++;
			}
			else
				num++;
			break;
		case 'n':
			if ((i + 1 != s.length()) && (s[i + 1] == 'j'))
			{
				i++; num++;
			}
			else
				num++;
			break;
		case 's':
			if ((i + 1 != s.length()) && (s[i + 1] == '='))
			{
				i++; num++;
			}
			else
				num++;
			break;
		case 'z':
			if ((i + 1 != s.length()) && (s[i + 1] == '='))
			{
				i++; num++;
			}
			else
				num++;
			break;
		default:
			num++;
		}
	}

	cout << num;

	return 0;
}