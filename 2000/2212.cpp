#include <iostream>
#include <algorithm>
#include <vector>
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
	vector<int> g;
	for (int i = N - 1; i > 0; i--)
		g.push_back(v[i] - v[i - 1]);
	sort(g.begin(), g.end());
	
	int answer = 0;
	for (int i = g.size() - K; i >= 0; i--)
		answer += g.at(i);

	cout << answer;

	return 0;
}