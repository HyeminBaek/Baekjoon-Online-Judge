#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, Q; cin >> N >> Q;
	vector<int> v;
	for (int i = 0; i < N; i++)
	{
		int x; cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());

	vector<int> sum;
	sum.push_back(v[0]);
	for (int i = 1; i < N; i++)
	{
		sum.push_back(sum[i - 1] + v[i]);
	}

	for (int i = 0; i < Q; i++)
	{
		int L, R; cin >> L >> R;
		if (L >= 2)
			cout << sum[R - 1] - sum[L - 2] << "\n";
		else
			cout << sum[R - 1] << "\n";
	}

	return 0;
}