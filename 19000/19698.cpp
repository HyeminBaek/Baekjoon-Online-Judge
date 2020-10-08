#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, W, H, L;
	cin >> N >> W >> H >> L;

	int num = (W / L)*(H / L);
	num = (num <= N) ? num : N;
	cout << num;

	return 0;
}