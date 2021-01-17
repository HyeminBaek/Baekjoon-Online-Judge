#include <iostream>
#include <string>
#include <set>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M; cin >> N >> M;
	
	set<string> v;
	for (int i = 0; i < N; i++)
	{
		string s; cin >> s;
		v.insert(s);
	}

	int answer = 0;
	for (int i = 0; i < M; i++)
	{
		string s; cin >> s;

		if (v.find(s) != v.end()) answer++;
	}

	cout << answer;

	return 0;
}