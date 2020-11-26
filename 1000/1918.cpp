#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s; cin >> s;
	vector<pair<int, char>> v;
	
	string answer = "";
	bool flag = false; //여는 괄호가 들어왔는가?
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= 65 && s[i] < 91)
			answer += s[i];
		else if (s[i] == '(')
			v.push_back({ 0,s[i] });
		else if (s[i] == '+' || s[i] == '-')
		{
			while (!v.empty() && v.back().first >= 1) // 우선순위가 같거나 높은 것 제거
			{
				answer += v.back().second;
				v.pop_back();
			}
			v.push_back({ 1,s[i] });
		}
		else if (s[i] == '*' || s[i] == '/')
		{
			while (!v.empty() && v.back().first > 1)
			{
				answer += v.back().second;
				v.pop_back();
			}
			v.push_back({ 2,s[i] });
		}
		else if (s[i] == ')')
		{
			while (!v.empty() && v.back().first != 0)
			{
				answer += v.back().second;
				v.pop_back();
			}
			v.pop_back(); //여는 괄호 제거
			flag = false;
		}
	}

	while (!v.empty())
	{
		answer += v.back().second;
		v.pop_back();
	}
	cout << answer;

	return 0;
}