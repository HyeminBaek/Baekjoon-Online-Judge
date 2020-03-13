#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int* rope = new int[n];

	for (int i = 0; i < n; i++)
		cin >> rope[i];
	
	sort(rope, rope + n);

	int temp = 0;

	for (int i = 0, j = n; i < n, j>0; i++, j--)
	{
		rope[i] *= j;
		temp = max(temp, rope[i]);
	}

	cout << temp;

	return 0;
}