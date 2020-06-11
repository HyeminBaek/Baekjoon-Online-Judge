#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	long long N, A, B, C;
	cin >> N; 

	vector<int> v;
	for (int i = 0; i < N; i++)
	{
		cin >> A;
		v.push_back(A);
	}

	cin >> B >> C;

	long long sum = N;
	for (int i = 0; i < v.size(); i++)
	{
		v[i] -= B;
		if (v[i] < 0) continue;
		if (v[i] % C != 0)
			sum++;
		sum += v[i] / C;
	}

	cout << sum;

	return 0;
}