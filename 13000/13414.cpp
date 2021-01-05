#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int K, L; cin >> K >> L;
	
	map<string, int> m;
	vector<string> v;
	string s[501];
	for (int i = 0; i < L; i++)
	{
		cin >> s[i];	m[s[i]]++;
	}

	int cnt = 0;
	for (int i = 0; i < L; i++)
	{
		if (m[s[i]] >= 2) m[s[i]]--;
		else
		{
			v.push_back(s[i]);
			cnt++; m[s[i]]--;
			if (cnt == K) break;
		}
	}
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << "\n";

	return 0;
}