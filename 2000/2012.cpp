#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	
	vector<int> v; v.push_back(-1);
	for (int i = 0; i < N; i++)
	{
		int x; cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());

	long long answer = 0;
	for (int i = 1; i < v.size(); i++)
		answer += abs(v[i] - i);

	cout << answer;

	return 0;
}