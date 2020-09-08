#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

int main()
{
	int N;
	while (cin >> N)
	{
		if (N == 0) break;
		
		string s; cin >> s;
		vector<string> v;

		for (int i = 0; i < s.length(); i += N)
		{
			string temp = "";
			if (v.size() % 2 == 1)
			{
				for (int j = N - 1; j >= 0; j--)
					temp += s[i + j];
			}
			else
				temp = s.substr(i, i + N);

			v.push_back(temp);
		}
		for (int j = 0; j < N; j++)
		{
			for (int i = 0; i < v.size(); i++)
			{
				cout << v[i][j];
			}
		}
		cout << endl;
	}

	return 0;
}