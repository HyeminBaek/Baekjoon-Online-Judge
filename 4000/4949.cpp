#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s;
	while (getline(cin, s))
	{
		if (s == ".") break;
		stack<char> st; bool flag = true;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == '(' || s[i] == '[')
				st.push(s[i]);
			if (s[i] == ')' || s[i] == ']')
			{
				if (st.empty())
				{
					cout << "no\n";
					flag = false; break;
				}
				if (s[i] == ')'&&st.top() == '(')
					st.pop();
				else if (s[i] == ']'&&st.top() == '[')
					st.pop();
				else
				{
					cout << "no\n";
					flag = false; break;
				}
			}
		}
		if (flag&&st.empty())
			cout << "yes\n";
		else if (flag && !st.empty())
			cout << "no\n";
	}
	return 0;
}