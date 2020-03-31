#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<string> s;
	s.push_back("*");

	for (int i = 0; i < n; i++)
	{
		cout << s[i]<<endl;
		if (i == 0)
			s.push_back(s.at(0) + "*");
		else
			s.push_back(s.at(i) + "*");
	}
	s.pop_back();
	s.pop_back();
	for (int i = s.size() - 1; i >= 0; i--)
	{
		cout << s[i]<<endl;
		s.pop_back();
	}
	

	return 0;
}