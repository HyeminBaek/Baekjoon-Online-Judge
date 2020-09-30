#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N; cin.ignore();
	for (int i = 1; i <= N; i++)
	{
		string s, temp =""; getline(cin, s);
		vector<string> v; 
		for (int j = 0; j < s.length(); j++)
		{

			if (s[j] == ' ')
			{
				v.push_back(temp);
				temp = "";
			}
			else
			{
				temp += s[j];
			}
		}
		v.push_back(temp);
		cout << "Case #" << i << ": ";
		for (int j = v.size() - 1; j >= 0; j--)
		{
			cout << v[j] << " ";
		}
		cout << endl;
	}
	return 0;
}