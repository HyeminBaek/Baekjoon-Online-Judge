#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<int> v1;
	vector<int> v2;
	
	for (int i = 0; i < 20; i++)
	{
		int x; cin >> x;
		if (i < 10)
			v1.push_back(x);
		else
			v2.push_back(x);
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	int sum = 0;
	for (int i = 7; i < 10; i++)
		sum += v1[i];
	cout << sum << " ";
	sum = 0;
	for (int i = 7; i < 10; i++)
		sum += v2[i];
	cout << sum;

	return 0;
}