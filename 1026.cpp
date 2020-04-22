#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	
	vector<int> a;
	vector<int> b;

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		a.push_back(x);
	}
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		b.push_back(x);
	}
	
	sort(a.begin(), a.end());

	int sum = 0;
	for (int j = 0; j < n; j++)
	{
		int maxIndex = max_element(b.begin(), b.end()) - b.begin();

		sum += a.front() * b[maxIndex];
		a.erase(a.begin());
		b.erase(b.begin()+maxIndex);
	}

	cout << sum;

	return 0;
}