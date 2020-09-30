#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;

	string* temp = new string[n];
	vector<char> cmd;

	for (int i = 0; i < n; i++)
		cin >> temp[i];

	for (int i = 0; i < temp[0].length(); i++)
		cmd.push_back(temp[0][i]);
	
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < temp[i].length(); j++)
		{
			if (cmd[j] != temp[i][j])
				cmd[j] = '?';
		}
	}

	for (int i = 0; i < cmd.size(); i++)
		cout << cmd[i];

	return 0;
}