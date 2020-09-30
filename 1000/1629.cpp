#include <iostream>
using namespace std;

long long div(long long a,long long b,long long c)
{
	if (b == 0) return 1;

	long long temp = div(a, b / 2, c);
	if (b % 2 == 1)
		return temp * temp % c * a % c;
	else
		return temp * temp % c;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	long long A, B, C;
	cin >> A >> B >> C;
	
	cout << div(A, B, C);

	return 0;
}