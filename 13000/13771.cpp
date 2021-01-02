#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	vector<double> v;

	for (int i = 0; i < N; i++)
	{
		double x; cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());

	cout << fixed << setprecision(2) << v[1];

	return 0;
}