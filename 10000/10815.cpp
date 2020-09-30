#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	vector<long long> nv;
	for (int i = 0; i < N; i++)
	{
		int x; cin >> x;
		nv.push_back(x);
	}

	sort(nv.begin(), nv.end());

	int M; cin >> M;
	vector <long long> mv;
	for (int i = 0; i < M; i++)
	{
		int x; cin >> x;
		mv.push_back(x);
	}

	for (int i = 0; i < M; i++)
	{
		if (upper_bound(nv.begin(), nv.end(), mv[i]) - lower_bound(nv.begin(), nv.end(), mv[i]) > 0)
			cout << 1 << " ";
		else cout << 0 << " ";
	}
	return 0;
}