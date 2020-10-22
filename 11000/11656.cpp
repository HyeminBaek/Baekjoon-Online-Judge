#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s; cin >> s;
	vector<string> v;
	v.push_back(s);
	for (int i = 1; i < s.length(); i++)
		v.push_back(s.substr(i, s.length() - 1));

	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << "\n";

	return 0;
}