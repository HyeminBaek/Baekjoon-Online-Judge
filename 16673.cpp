#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int C, K, P; cin >> C >> K >> P;
	int sum = 0;

	while (C > 0)
	{
		sum += C * K + P * C*C;
		C--;
	}
	cout << sum;

	return 0;
}