#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	long long arr[80001] = { 0, };
	int last = 0;
	for (int i = 1; i < 80001; i++)
	{
		if (i % 21 == 0)
		{
			arr[i] = arr[last];
			arr[i] += i;
			last = i;
		}
		else if (i % 3 == 0 || i % 7 == 0)
		{
			arr[i] = arr[last];
			arr[i] += i;
			last = i;
		}
		else
			arr[i] = arr[last];
	}

	int T; cin >> T;
	for (int i = 0; i < T; i++)
	{
		int N; cin >> N;
		cout << arr[N]<<"\n";
	}
	return 0;
}