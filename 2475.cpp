#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int answer = 0;
	for (int i = 0; i < 5; i++)
	{
		int x; cin >> x;
		answer += x * x;
	}

	cout << answer % 10;

	return 0;
}