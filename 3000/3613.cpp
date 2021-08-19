#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s; cin >> s;

	int flag = -1;
	string answer = "";
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= 65 && s[i] < 91)
		{
			answer += '_';
			answer += tolower(s[i]);
			if (i == 0)
			{
				flag = 404; break;
			}
			if (flag == -1 || flag == 0)
				flag = 0;
			else
			{
				flag = 404; break;
			}
		}
		else if (s[i] == '_')
		{
			if (s[i + 1] >= 65 && s[i + 1] < 91)
			{
				flag = 404; break;
			}
			if (i == 0 || i == s.length() - 1 || s[i + 1] == '_')
			{
				flag = 404; break;
			}
			if (flag == -1 || flag == 1)
				flag = 1;
			else
			{
				flag = 404; break;
			}
			//if(i<s.length())
			answer += toupper(s[++i]);
		}
		else
			answer += s[i];
	}

	if (flag == 404)
		cout << "Error!";
	else if (flag == -1)
		cout << s;
	else	cout << answer;

	return 0;
}
