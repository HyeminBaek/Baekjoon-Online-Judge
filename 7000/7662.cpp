#include <iostream>
#include <set>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;
	for (int t = 0; t < T; t++)
	{
		int k; cin >> k;

		multiset<int> Q;
		for (int i = 0; i < k; i++)
		{
			char c; int n;
			cin >> c >> n;

			if (c == 'D')
			{
				if (Q.size()>0)
				{
					if (n == 1)
					{
						auto idx = Q.end(); idx--;
						Q.erase(idx);
					}
					else
						Q.erase(Q.begin());
				}
			}
			else if (c == 'I')
				Q.insert(n);
		}
		if (Q.empty())	cout << "EMPTY\n";
		else
			cout << *(--Q.end()) << " " << *(Q.begin()) << "\n";
	}

	return 0;
}