#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s; cin >> s;
	int N; cin >> N;

	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		string temp; cin >> temp;

		for (int j = 0; j < temp.length(); j++)
		{
			if (temp.substr(j, s.length()) == s)
			{
				answer++; break;
			}
			if (j + s.length() > temp.length())
			{
				string sub = "";
				for (int k = 0; k < s.length(); k++)
				{
					sub += temp[((j + k) % (temp.length()))];
				}
				//cout << sub << endl;
				if (sub == s)
				{
					answer++; break;
				}
			}
		}
	}
	cout << answer;

	return 0;
}