#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;

	vector<int> v;
	for (int i = 0; i < N; i++)
	{
		int x; cin >> x;
		v.push_back(x);
	}

	bool flag = prev_permutation(v.begin(), v.end());

	if (!flag) cout << -1;
	else
	{ 
		for (int i = 0; i < N; i++)
			cout << v[i] << " ";
	}

	return 0;
}