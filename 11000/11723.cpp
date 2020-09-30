#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	bool S[20]; memset(S, false, sizeof(S));
	int M; cin >> M;
	for (int i = 0; i < M; i++)
	{
		string s; cin >> s;
		if (s == "add")
		{
			int x; cin >> x;
			S[x - 1] = true;
		}
		if (s == "remove")
		{
			int x; cin >> x;
			S[x - 1] = false;
		}
		if (s == "check")
		{
			int x; cin >> x;
			if (S[x - 1]) cout << 1 << "\n";
			else cout << 0 << "\n";
		}
		if (s == "toggle")
		{
			int x; cin >> x;
			if (S[x - 1]) S[x - 1] = false;
			else S[x - 1] = true;
		}
		if (s == "all")
		{
			for (int j = 0; j < 20; j++)
			{
				if (S[j]) continue;
				S[j] = true;
			}
		}
		if (s == "empty")
		{
			for (int j = 0; j < 20; j++)
			{
				if (!S[j]) continue;
				S[j] = false;
			}
		}
	}
	return 0;
}