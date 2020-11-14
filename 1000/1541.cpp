#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s; cin >> s;

	vector<string> v;
	string temp = "";
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '-' || s[i] == '+')
		{
			v.push_back(temp); 
			v.push_back(to_string(s[i]));
			if(s[i]=='-')

			temp = "";
		}
		else
			temp += s[i];
	}

	
	return 0;
}