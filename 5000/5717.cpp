#include <iostream>
using namespace std;

int sum(int m, int w)
{
	return m + w;
}
int main()
{
	int m, w;
	while (cin >> m >> w)
	{
		if (m == 0 && w == 0) break;
		cout << sum(m, w) << endl;
	}

	return 0;
}