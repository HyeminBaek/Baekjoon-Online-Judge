#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int A, B; cin >> A >> B;

	vector<int> v;
	for (int i = 1; i <= B; i++)
	{
		for (int j = 1; j <= i; j++)
			v.push_back(i);

		if (v.size() == B) break;
	}

	int sum = 0;
	for (int i = A - 1; i < B; i++)
		sum += v[i];

	cout << sum;

	return 0;
}