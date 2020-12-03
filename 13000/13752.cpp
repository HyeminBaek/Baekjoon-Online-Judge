#include <iostream>
using namespace std;

int main()
{
	int T; cin >> T;
	for (int i = 0; i < T; i++)
	{
		int x; cin >> x;
		for (int j = 0; j < x; j++)
			cout << '=';
		cout << endl;
	}

	return 0;
}