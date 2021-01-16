#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, K; cin >> N >> K;
	
	vector<int> v;
	for (int i = 0; i < N; i++)
	{
		int x; cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());

	cout << v[K - 1];

	return 0;
}