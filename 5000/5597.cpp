#include <iostream>
using namespace std;

int main()
{
	bool stu[31] = { false, };
	for (int i = 0; i < 28; i++)
	{
		int x; cin >> x;

		stu[x] = true;
	}
	for (int i = 1; i < 31; i++)
	{
		if (!stu[i])
			cout << i << "\n";
	}

	return 0;
}