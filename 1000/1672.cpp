#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

map<string, char> m;
vector<char> v;

void sol()
{
	string tmp = "";
	while (1)
	{
		if (tmp.length() == 2)
		{
			v.push_back(m[tmp]);
			tmp = "";
			if (v.size() == 1) break;
		}
		tmp = v.back() + tmp;
		v.pop_back();
	}

	cout << v.front();
}
void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;
	for (int i = 0;i<n;i++)
	{
		char c; cin >> c;
		v.push_back(c);
	}

	m.insert({ "AA",'A' }); m.insert({ "GA",'C' }); m.insert({ "CA",'A' }); m.insert({ "TA",'G' });
	m.insert({ "AG",'C' }); m.insert({ "GG",'G' }); m.insert({ "CG",'T' }); m.insert({ "TG",'A' });
	m.insert({ "AC",'A' }); m.insert({ "GC",'T' }); m.insert({ "CC",'C' }); m.insert({ "TC",'G' });
	m.insert({ "AT",'G' }); m.insert({ "GT",'A' }); m.insert({ "CT",'G' }); m.insert({ "TT",'T' });
}
int main()
{
	init();
	sol();

	return 0;
}
