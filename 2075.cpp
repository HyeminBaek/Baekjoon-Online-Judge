#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int* input = new int[n*n];

	for (int i = 0; i < n*n; i++)
		cin >> input[i];

	sort(input, input + n * n);

	cout << input[n*n - n];

	return 0;
}