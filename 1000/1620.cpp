#include <iostream>
#include <string>
#include <map>
#include <iomanip>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M; cin >> N >> M;

	map<string, int> m;
	string arr[100001];
	for (int i = 1; i <= N; i++)
	{
		string s; cin >> s;
		m.insert({ s,i });
		arr[i] = s;
	}
	for (int i = 0; i < M; i++)
	{
		string s; cin >> s;
		if (isdigit(s[0]))
			cout << arr[stoi(s)] << "\n";
		else
			cout << m[s] << "\n";
	}
	return 0;
}