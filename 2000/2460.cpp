#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int arr[10] = { 0, };

	int max = 0;
	for (int i = 0; i < 10; i++)
	{
		int in, out; cin >> out >> in;
		if (i > 0) arr[i] = arr[i - 1];
		arr[i] -= out; arr[i] += in;

		max = (max < arr[i]) ? arr[i] : max;
	}
	cout << max;

	return 0;
}