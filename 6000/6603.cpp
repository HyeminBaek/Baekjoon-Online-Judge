#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

void dfs(int k,string s)
{
	if (k == 6)
	{
		cout << s << "\n";
		return;
	}
	for (int i = 0; i < v.size(); i++)
	{
		string temp = "";
		if (!s.empty())
		{
			for (int i = s.length() - 1; i >= 0; i--)
			{
				if (s[i] == ' ') break;
				temp = s[i] + temp;
			}
		}
		if (s.empty() || v[i] > stoi(temp))
		{
			if (s.empty())
				dfs(k + 1, to_string(v[i]));
			else
				dfs(k + 1, s + " " + to_string(v[i]));
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (1)
	{
		int N; cin >> N;

		if (N == 0) break;
		v.clear();
		for (int i = 0; i < N; i++)
		{
			int x; cin >> x;
			v.push_back(x);
		}

		dfs(0, "");

		cout << "\n";
	}

	return 0;
}