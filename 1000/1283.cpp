#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

void print(vector<string> v, int idx)
{

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	cin.ignore();

	bool ABC[26] = { false, };

	for (int T = 0; T < N; T++)
	{
		string s; getline(cin, s);
		vector<string> v;
		string temp = "";
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == ' ')
			{
				v.push_back(temp);
				temp = "";
			}
			else
				temp += s[i];
		}
		v.push_back(temp);

		//첫 번째 지정 방법
		bool flag = false; //단축키가 설정되었는지 나타내는 변수
		for (int i = 0; i < v.size(); i++)
		{
			if (!ABC[toupper(v[i][0]) - 'A'])
			{
				ABC[toupper(v[i][0]) - 'A'] = true;
				flag = true;
				for (int j = 0; j < i; j++)
					cout << v[j] << " ";
				cout << "[" << v[i][0] << "]";
				for (int j = 1; j < v[i].length(); j++)
					cout << v[i][j];
				cout << " ";
				for (int j = i + 1; j < v.size(); j++)
					cout << v[j] << " ";
				cout << "\n";
				break;
			}
		}
		if (!flag)//첫 글자가 모두 지정되어 있는 경우
		{
			for (int i = 0; i < v.size(); i++)
			{
				if (flag) break;

				for (int j = 1; j < v[i].length(); j++)
				{
					if (!ABC[toupper(v[i][j]) - 'A'])
					{
						ABC[toupper(v[i][j]) - 'A'] = true;
						flag = true;
						for (int k = 0; k < i; k++)
							cout << v[k] << " ";
						for (int k = 0; k < j; k++)
							cout << v[i][k];
						cout << "[" << v[i][j] << "]";
						for (int k = j + 1; k < v[i].length(); k++)
							cout << v[i][k];
						cout << " ";
						for (int k = i + 1; k < v.size(); k++)
							cout << v[k] << " ";
						cout << "\n";
						break;
					}
				}
			}
			if (!flag)
			{
				for (int i = 0; i < v.size(); i++)
					cout << v[i] << " ";
				cout << "\n";
			}
		}
	}
	return 0;
}