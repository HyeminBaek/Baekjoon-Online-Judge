#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		if (n == -1) break;
		vector<int> v;

		int sum = 0;
		for (int i = 1; i < n; i++)
		{
			if (n % i == 0)
			{
				sum += i;	v.push_back(i);
			}
		}
		if (sum == n)
		{
			cout << n << " = ";
			for (int i = 0; i < v.size(); i++)
			{
				cout << v[i];
				if (i < v.size() - 1)
					cout << " + ";
			}
			cout << endl;
		}
		else
			cout << n << " is NOT perfect.\n";
	}

	return 0;
}