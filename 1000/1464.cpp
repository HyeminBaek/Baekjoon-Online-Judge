#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s; cin >> s;
	//i��° �ε����� i-1��°���� ���������� �ڸ� 0��° �ε����� ����
	
	for (int i = 1; i < s.length(); i++)
	{
		string temp = "";

		if (s[i] > s[i - 1])
		{
			temp = s[i];

			for (int j = 0; j < s.length(); j++)
			{
				if (i != j)
					temp += s[j];
			}

			s = temp;
		}
	}
	reverse(s.begin(), s.end());
	cout << s;

	return 0;
}