#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<char> v;

	int answer = 0;
	string s; cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(')
			v.push_back(s[i]);
		else
		{
			if (s[i - 1] == '(')
			{
				v.pop_back();
				answer+=v.size();
			}
			else
			{
				v.pop_back();
				answer++;
			}
		}
	}

	cout << answer;

	return 0;
}