#include <iostream>
#include <string>
using namespace std;

int main()
{
	int a;

	while (cin >> a)
	{
		if (a == 0) break;

		string A;
		A = to_string(a);

		bool flag = true;
		for (int i = 0; i < A.length() / 2; i++)
		{
			if (A[i] != A[A.length() - 1 - i])
				flag = false;
		}
		if (!flag) cout << "no\n";
		else cout << "yes\n";
	}
	return 0;
}