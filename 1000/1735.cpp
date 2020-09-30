#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int A, B, C, D; cin >> A >> B >> C >> D;
	int J = A * D + C * B, M = B * D;

	for (int i = min(J, M); i > 1; i--)
	{
		if (J%i == 0 && M%i == 0)
		{
			J /= i; M /= i; break;
		}
	}
	cout << J << " " << M;

	return 0;
}