#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	long long arr[101][10] = { 0, };
	int N; cin >> N;

	for (int i = 1; i < 10; i++)
		arr[1][i] = 1;

	for (int i = 2; i <= N; i++)
	{

		arr[i][0] = arr[i - 1][1];
		arr[i][9] = arr[i - 1][8];

		for (int j = 1; j < 9; j++)
			arr[i][j] = (arr[i - 1][j - 1] + arr[i - 1][j + 1]) % 1000000000;
	}
	long long sum = 0;
	for (int i = 0; i < 10; i++)
		sum += arr[N][i];

	cout << sum % 1000000000;

	return 0;
}